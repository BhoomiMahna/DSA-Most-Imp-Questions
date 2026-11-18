class Solution {
public:
    int minChanges(string s) {
        
        int n = s.length();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,INT_MAX)));

        dp[0][s[0]-'0'][1] = 0;
        dp[0]['1'-s[0]][1] = 1;

        for(int i = 1;i<n;i++) {

            int best = min(dp[i-1][1][0],dp[i-1][0][0]);

            int ch = s[i]-'0';
            dp[i][ch][0] = dp[i-1][ch][1];
            dp[i][ch][1] = best;

            int counter = '1'-s[i];
            dp[i][counter][0] = (dp[i-1][counter][1] == INT_MAX) ? INT_MAX : dp[i-1][counter][1]+1;
            dp[i][counter][1] = (best == INT_MAX) ? INT_MAX : best + 1;

        }

        return min(dp[n-1][0][0],dp[n-1][1][0]);
    }
};