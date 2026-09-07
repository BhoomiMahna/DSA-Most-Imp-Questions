class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> last(26, 0);

        for (int i = 0; i < n; i++) {
            dp[i + 1] = (2LL * dp[i]) % MOD;
            dp[i + 1] =(dp[i + 1] - last[s[i] - 'a'] + MOD) % MOD;
            last[s[i] - 'a'] = dp[i];
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};