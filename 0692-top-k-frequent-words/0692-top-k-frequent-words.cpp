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
    void search(string word,unordered_map<string,int>&freq){
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]==nullptr){
                return;
            }
            curr=curr->children[idx];
        }
        if(curr->eow)freq[word]++;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(int i=0;i<words.size();i++){
            insert(words[i]);
        }
        for(int i=0;i<words.size();i++){
            search(words[i],freq);
        }
        vector<pair<string, int>> arr;
        for(auto x:freq) {
            arr.push_back({x.first,x.second});
        }
        sort(arr.begin(), arr.end(), [](pair<string, int>& a, pair<string, int>& b){
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first<b.first;
        });

        vector<string> ans;
        for (int i=0;i<k;i++) {
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};