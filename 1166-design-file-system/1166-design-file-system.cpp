class FileSystem {
public:
    class Node{
        public:
        unordered_map<string,Node*> children;
        bool eow;
        int val;
        Node(){
            val=-1;
            eow=false;
        }
    };
    Node* root;
    vector<string> split(string path){
        vector<string>parts;
        string temp="";
        for(int i=1;i<path.size();i++){
            if(path[i]=='/'){
                parts.push_back(temp);
                temp="";
            }
            else{
                temp+=path[i];
            }
        }
        parts.push_back(temp);
        return parts;
    }
    
    FileSystem() {
        root=new Node();
    }
    
    bool createPath(string path, int value) {
        vector<string> parts=split(path);
        Node* curr=root;
        for(int i=0;i<parts.size()-1;i++){
            if(curr->children.count(parts[i])==0)return false;
            curr=curr->children[parts[i]];
        }
        string last=parts.back();
        if(curr->children.count(last)) return false;
        curr->children[last]=new Node();
        curr=curr->children[last];
        curr->eow=true;
        curr->val=value;
        return true;
    }
    
    int get(string path) {
        vector<string>parts=split(path);
        Node* curr=root;
        for(string dir:parts){
            if(curr->children.count(dir)==0)return -1;
            curr=curr->children[dir];
        }
        if(!curr->eow)return -1;
        return curr->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */