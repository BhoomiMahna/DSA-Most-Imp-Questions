class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int count=0;
        for(char c:s){
            if(c=='1')count++;
        }
        string st="1";
        st+=s;
        st+="1";
        vector<char>ch;
        vector<int>len;
        for(int i=0;i<st.size();){
            char c=st[i];
            int j=i;
            while(j<st.size() && st[j]==c){
                j++;
            }
            ch.push_back(c);
            len.push_back(j-i);
            i=j;
        }
        int ans=count;
        for(int i=1;i+1<ch.size();i++){
            if(ch[i]=='1' && ch[i-1]=='0' && ch[i+1]=='0'){
                ans=max(ans,count+len[i-1]+len[i+1]);
            }
        }
        return ans;
    }
};