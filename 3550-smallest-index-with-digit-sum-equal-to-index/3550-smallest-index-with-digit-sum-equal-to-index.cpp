class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            int res = 0;

            while (nums[i] > 0) {
                res += nums[i] % 10;
                nums[i] /= 10;
            }

            if (res == i) {
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());

        if (ans.empty()) {
            return -1;
        } else {
            return ans[0];
        }
    }
};