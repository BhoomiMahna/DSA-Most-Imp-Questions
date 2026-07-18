class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small=*min_element(nums.begin(),nums.end());
        int big=*max_element(nums.begin(),nums.end());

        if(big%small==0){
            return small;
        }
        int gcd=1;
        for(int i=small-1;i>=0;i--){
            if(small%i==0 && big%i==0){
                gcd=i;
                break;
            }
        }
        return gcd;
    }
};