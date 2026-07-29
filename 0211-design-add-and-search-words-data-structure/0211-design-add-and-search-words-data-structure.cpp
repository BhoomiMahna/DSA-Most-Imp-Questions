class WordDictionary {
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

    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string s) {
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
    bool dfs(string &s,int pos,Node* node){
        if(node==nullptr)return false;
        if(pos==s.size())return node->eow;
        
        if(s[pos]=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i] && dfs(s,pos+1,node->children[i]))return true;
            }
            return false;
        }
        int idx=s[pos]-'a';
        return dfs(s,pos+1,node->children[idx]);
    }
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */