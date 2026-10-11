class Solution {
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
    Node* root=new Node();
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
    bool search(string s){
        Node* curr=root;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            if(curr->children[idx]==nullptr){
                return false;
            }
            curr=curr->children[idx];
        }
        return curr->eow;
    }
    vector<string> partitionString(string s) {
        vector<string>ans;
        string seg="";
        for(char c:s){
            seg+=c;
            if(!search(seg)){
                ans.push_back(seg);
                insert(seg);
                seg="";
            }
        }
        return ans;
    }
};