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
    void insert(string word){
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new Node();
            }
            curr=curr->children[idx];
        }
        curr->eow=true;
    }
    bool check(string word){
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            curr=curr->children[idx];
            if(curr->eow==false){
                return false;
            }
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            insert(words[i]);
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(check(words[i])){
                if(words[i].size()>ans.size() || words[i].size()==ans.size() && words[i]<ans){
                    ans=words[i];
                }
            }
        }
        return ans;
    }
};