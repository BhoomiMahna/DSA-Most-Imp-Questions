class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int prev=nums[0];
       
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev+1){
                sum+=nums[i];
                prev=nums[i]; 
            }
            else{
                break;
            }
        }
        int ans=sum;
        unordered_set<int>s1(nums.begin(),nums.end());

        while(s1.count(ans)){
            ans++;
        }
        return ans;
    }
};