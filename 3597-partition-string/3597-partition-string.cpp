class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>ans;
        unordered_set<string>seen;
        string seg="";
        for(char c:s){
            seg+=c;
            if(seen.find(seg)==seen.end()){
                ans.push_back(seg);
                seen.insert(seg);
                seg="";
            }
        }
        return ans;
    }
};