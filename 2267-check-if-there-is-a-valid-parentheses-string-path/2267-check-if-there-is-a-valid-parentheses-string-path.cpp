class Solution {
public:
    int m, n;
    bool helper(vector<vector<char>>& grid, int row, int col, int count,vector<vector<vector<int>>>& dp) {
        if(row >= m || col >= n) return false;
        if(grid[row][col] == '(') count++;
        else count--;
        if(count < 0) return false;
        int remaining = (m - row - 1) + (n - col - 1);
        if(count > remaining) return false;
        if(dp[row][col][count] != -1)return dp[row][col][count];
        if(row == m - 1 && col == n - 1)return count == 0;
        bool right = helper(grid, row, col + 1, count, dp);
        bool down = helper(grid, row + 1, col, count, dp);
        return dp[row][col][count] = right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if((m + n - 1) % 2)return false;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        return helper(grid, 0, 0, 0, dp);
    }
};