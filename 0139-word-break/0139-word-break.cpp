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
    unordered_map<string,bool>dp;
    void insert(string word){
        Node* curr=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new Node();
            }
            curr=curr->children[idx];
        }
        curr->eow=true;
    }
    bool search(string key){
        Node *curr=root;
        for(int i=0;i<key.length();i++){
            int idx=key[i]-'a';
            if(curr->children[idx]==nullptr){
                return false;
            }
            curr=curr->children[idx];
        }
        return curr->eow;
    }
    bool solve(string s){
        if(s.length()==0)return true;
        if(dp.count(s))return dp[s];
        for(int i=1;i<=s.length();i++){
            string first=s.substr(0,i);
            string second=s.substr(i);

            if(search(first) && solve(second)){
                return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict){
            insert(word);
        }
        return solve(s);
    }
};