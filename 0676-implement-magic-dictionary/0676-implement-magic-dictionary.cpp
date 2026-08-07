class MagicDictionary {
public:
    class Node{
        public:
        Node* children[26];
        bool eow;
        Node(){
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
            eow=false;
        }
    };
        Node* root;
        void insert(string s){
            Node* curr=root;
            for(int i=0;i<s.size();i++){
                int idx=s[i]-'a';
                if(curr->children[idx]==nullptr){
                    curr->children[idx]=new Node();
                }
                curr=curr->children[idx];
            }
            curr->eow=true;
        }
        bool dfs(Node* curr,int pos,string &word, bool changed){
            if(curr==nullptr)return false;
            if(pos==word.size())return changed && curr->eow;
            int idx=word[pos]-'a';
            
            if(curr->children[idx] && dfs(curr->children[idx],pos+1,word,changed))return true;
            if(!changed){
                for(int i=0;i<26;i++){
                    if(i==idx)continue;
                    if(curr->children[i]&& dfs(curr->children[i],pos+1,word,true))return true;
                }
            }
            return false;
        }
    
    MagicDictionary() {
        root=new Node();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string &w:dictionary){
            insert(w);
        }
    }
    
    bool search(string searchWord) {
        return dfs(root,0,searchWord,false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */