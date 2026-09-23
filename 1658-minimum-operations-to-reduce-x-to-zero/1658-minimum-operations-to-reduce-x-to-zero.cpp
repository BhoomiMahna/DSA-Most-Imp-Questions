class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();       
        long long total = 0;
        for(int num : nums) {
            total += num;
        }
        long long target = total - x;
        if(target < 0) return -1;
        if(target == 0) return n;
        unordered_map<long long, int> mpp;
        mpp[0] = -1;
        long long sum = 0;
        int maxi = -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mpp.count(sum - target)) {
                maxi = max(maxi, i - mpp[sum - target]);
            }
            mpp[sum] = i;
        }
        if(maxi == -1) return -1;
        return n - maxi;
    }
};