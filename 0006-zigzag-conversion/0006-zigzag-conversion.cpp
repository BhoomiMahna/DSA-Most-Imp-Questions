class Solution {
public:
    string convert(string s, int k) {
        int len=s.length();
        string ans="";
        bool jump=true;
        int currow=0;
        int curridx=0;
        int x=(k-1)+(k-2);
        int y=x;

        if(k==1 || s.length()<=k)return s;
        for(int i=0;i<s.length();i++){
            ans+=s[curridx];
            if(currow>0 && currow<k-1){
                if(jump){
                    curridx+=y-2*currow+1;
                }
                else curridx+=2*currow;
                jump=!jump;
            }
            else{
                curridx+=(y+1);
            }
            if(curridx>len-1){
                currow++;
                curridx=currow;
                jump=true;
            }
        }
        return ans;
    }
};