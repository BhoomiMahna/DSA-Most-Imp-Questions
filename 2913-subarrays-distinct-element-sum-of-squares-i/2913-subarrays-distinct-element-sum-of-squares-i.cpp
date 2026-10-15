class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int l=0;l<n;l++){
            unordered_set<int>s;
            for(int r=l;r<n;r++){
                s.insert(nums[r]);
                int size=s.size();
                ans+=size*size;
            }
        }
        return ans;
    }
};