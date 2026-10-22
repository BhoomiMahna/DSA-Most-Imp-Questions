class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        if(n==0 || n==1)return 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]+1 && nums[i]!=nums[i+1]-1)count++;
        }
        if(count>=2 || (count==1 && nums[0]!=nums[n-1]+1 && nums[0]!=nums[n-1]-1))return -1;
        if(count==0 && nums[0]>nums[1])return 1;
        if(count==1){
            if(nums[0]==nums[1]+1 || nums[n-1]+1==nums[n-1]){
                count=0;
                for(int i=0;i<n-1;i++){
                    count++;
                    if(nums[i]<nums[i+1])break;
                }
                if(count>n/2){
                    return 1+n-count;
                }
                else return count+1;
            }
            else{
                count=0;
                for(int i=0;i<n-1;i++){
                    count++;
                    if(nums[i]>nums[i+1])break;
                }
                if(count==n/2+1)return count;
                else if(count>n/2)return 2+n-count;
                else return count;
            }
        }
        return 0;
    }
};