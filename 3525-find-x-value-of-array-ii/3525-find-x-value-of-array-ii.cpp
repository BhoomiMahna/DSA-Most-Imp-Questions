class Solution {
public:
    vector<array<int, 5>> v;
    vector<int> p;
    vector<int> nums;
    int s, k, n;

    vector<int> resultArray(vector<int>& nums1, int k1, vector<vector<int>>& queries) {
        nums = nums1, k = k1, n = nums.size();
        for (int& x : nums) 
            x %= k;
        s = sqrt(n);
        int blocks = (n + s - 1) / s;
        v.resize(blocks);
        p.resize(blocks);
        for (int b = 0; b < blocks; ++b) 
            rebuild(b);
        vector<int> ans;
        for (auto& q : queries) {
            int ind = q[0], val = q[1], start = q[2], x = q[3];
            update(ind, val);
            ans.push_back(query(start, x));
        }
        return ans;
    }

    void rebuild(int block) {
        v[block] = {};
        int cur = 1 % k;
        int left = block * s;
        int right = min(n, left + s);
        for (int i = left; i < right; ++i) {
            cur = (cur * nums[i]) % k;
            ++v[block][cur];
        }
        p[block] = cur;
    }

    void update(int i, int val) {
        nums[i] = val % k;
        rebuild(i / s);
    }

    int query(int i, int x) {
        int cur = 1 % k;
        int ans = 0;
        int end = min(n, i - (i % s) + s);
        for (; i < end; ++i) {
            cur = (cur * nums[i]) % k;
            ans += cur == x;
        }
        int block = (i + s - 1) / s;
        for (; block < (int)v.size(); ++block) {
            for (int r = 0; r < k; ++r) {
                if ((cur * r) % k == x) {
                    ans += v[block][r];
                }
            }
            cur = (cur * p[block]) % k;
        }
        return ans;
    }
};