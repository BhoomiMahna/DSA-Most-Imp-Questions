class Solution {
public:
    vector<string>ans;
    void find(string &word, int idx, string curr, int count){
        if(idx==word.size()){
            if(count>0){
                curr+=to_string(count);
            }
            ans.push_back(curr);
            return;
        }
        find(word,idx+1,curr,count+1);
        string next=curr;
        if(count>0){
            next+=to_string(count);
        }
        next+=word[idx];
        find(word,idx+1,next,0);
    }
    vector<string> generateAbbreviations(string word) {
        find(word,0,"",0);
        return ans;
    }
};