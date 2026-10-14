class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum)return "";
        string ans(num,'0');
        int nines=sum/9;
        int rem=sum%9;
        for(int i=0;i<nines;i++){
            ans[i]='9';
        }
        if(rem>0){
            ans[nines]=(char)('0'+rem);
        }
        return ans;
    }
};