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
    string search(string word){
        Node* curr=root;
        string ans="";
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]==nullptr)return word;
            curr=curr->children[idx];
            ans.push_back(word[i]);
            if(curr->eow)return ans;
        }
        return word;
        
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string &s:dictionary){
            insert(s);
        }
        stringstream ss(sentence);
        string word;
        string ans="";
        while(ss>>word){
            ans+=search(word);
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};