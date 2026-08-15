class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        bool allzero=true;
        for(int r=0;r<nums.size();r++){
            x^=nums[r];
            if(nums[r]!=0) allzero=false;
        }
        if(allzero)return 0;
        if(x!=0)return nums.size();
        return nums.size()-1;
    }
};