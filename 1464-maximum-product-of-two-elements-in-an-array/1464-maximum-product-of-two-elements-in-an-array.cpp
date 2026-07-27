class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstmax=nums[0];
        int secmax=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>firstmax){
                secmax=firstmax;
                firstmax=nums[i];
            }
            else if(nums[i]>secmax){
                secmax=nums[i];
            }
        }
        return (firstmax-1)*(secmax-1);
    }
};