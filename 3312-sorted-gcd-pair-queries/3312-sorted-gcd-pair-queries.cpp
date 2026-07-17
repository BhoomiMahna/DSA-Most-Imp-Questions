class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int maxi = 0;
        for (int x : nums) maxi = max(maxi, x);
        vector<int> freq(maxi + 1, 0);
        for (int x : nums) freq[x]++;
        vector<long long> gcdCount(maxi + 1, 0);
        for (int g = maxi; g >= 1; g--) {
            long long cnt = 0;
            for (int j = g; j <= maxi; j += g) cnt += freq[j];
            gcdCount[g] = cnt * (cnt - 1) / 2;
            for (int j = 2 * g; j <= maxi; j += g)gcdCount[g] -= gcdCount[j];
        }
        vector<long long> pref(maxi + 1, 0);
        for (int i = 1; i <= maxi; i++)
            pref[i] = pref[i - 1] + gcdCount[i];
        vector<int> ans;
        for (long long q : queries) {
            int l = 1;
            int r = maxi;
            while (l < r) {
                int mid = (l + r) / 2;
                if (pref[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};