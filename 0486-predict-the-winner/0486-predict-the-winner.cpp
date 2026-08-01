class Solution {
public:
    int find(int i,int j,vector<int>&nums){
        if(i==j)return nums[i];
        int pickleft=nums[i]-find(i+1,j,nums);
        int pickright=nums[j]-find(i,j-1,nums);

        return max(pickleft,pickright);
    }
    bool predictTheWinner(vector<int>& nums) {
        // 1 5 233 7 
        int n=nums.size();
        return find(0,n-1,nums)>=0;
    }
};