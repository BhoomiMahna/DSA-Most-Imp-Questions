class Solution {
public:
    long long sumAndMultiply(int n) {
        string s="";
        int sum=0;
        while(n!=0){
            int r=n%10;
            if(r!=0){
                s+=to_string(r);
                sum+=r;
            }
            n=n/10;
        }
        if(s.empty())return 0;
        reverse(s.begin(),s.end());
        long long x=stoi(s);
        return (long long)x*sum;
    }
};