class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            int q=nums[i]/k;
            if(nums[i]%k==0){
                s.insert(q);
            }
        }
        int q=1;
        while(s.count(q)){
            q++;
        }
        return q*k;
    }
};