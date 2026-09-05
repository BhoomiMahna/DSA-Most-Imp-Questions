class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int minval = INT_MAX, maxval = INT_MIN, n = nums.size();
        vector<int> temp(n);
        for(int i = n-1; i>=0; i--){
            minval = min(minval, nums[i]);
            temp[i] = minval;
        }

        for(int i = 0; i<n; i++){
            maxval = max(maxval, nums[i]);
            if(maxval - temp[i] <= k) return i;
        }
        return -1;
    }
};