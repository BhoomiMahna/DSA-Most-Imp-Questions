class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        string acc="";
        for(char& ch:searchWord){
            acc.push_back(ch);
            vector<string>match;
            for(string& p:products){
                if(p.size()<acc.size())continue;
                bool valid=true;
                for(int i=0;i<acc.size();i++){
                    if(p[i]!=acc[i]){
                        valid=false;
                        break;
                    }
                }
                if(valid)match.push_back(p);
            }
            sort(match.begin(),match.end());
            vector<string> temp;
            for (int i = 0; i < min(3, (int)match.size()); i++) {
                temp.push_back(match[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};