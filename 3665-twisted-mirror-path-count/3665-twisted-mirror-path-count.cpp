class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        static constexpr int LIMIT = 1e9 + 7;  
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);  
        dp[0] = 1;  
        for(int i = 0; i < m; ++i){
            for(int j = 0, prev = 0; j < n; ++j){
                if(grid[i][j] == 1) swap(prev, dp[j]);
                else dp[j] = prev = (prev + dp[j]) % LIMIT;
                
            }
        }

        return dp[n - 1];   
    }
};