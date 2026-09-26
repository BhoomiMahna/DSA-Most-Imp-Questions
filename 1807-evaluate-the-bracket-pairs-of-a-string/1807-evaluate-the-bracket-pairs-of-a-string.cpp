class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();++i){
            mp.insert({knowledge[i][0],knowledge[i][1]});
        }
        bool start=false;
        string ans;
        ans.reserve(s.length());
        string st;
        st.reserve(10);
        for(char c:s){
            if(c=='(')start=true;
            if(!start){
                ans+=c;
            }
            if(start&&c!='('&&c!=')'){
                st+=c;
            }
            if(c==')'){
                start=false;
                if(mp.contains(st)){
                    ans+=mp[st];
                }
                else{
                    ans+='?';
                }
                st.clear();
            }
        }
        return ans;
    }
};