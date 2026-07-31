class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int n=s.size();
        vector<bool>bold(n,false);
        for(string &w:words){
            int pos=s.find(w);
            while(pos!=string::npos){
                for(int i=pos;i<pos+w.size();i++){
                    bold[i]=true;
                }
                pos=s.find(w,pos+1);
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(bold[i] && (i==0|| !bold[i-1])){
                ans+="<b>";
            }
            ans+=s[i];
            if(bold[i] && (i==n-1||!bold[i+1])){
                ans+="</b>";
            }
        }
        return ans;
    }
};