class Solution {
public:
    int n,m;
    
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(1024,false)));
        dp[0][0][grid[0][0]]=true;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
                for(int x=0;x<1024;x++){
                    if(i>0 && dp[i-1][j][x])dp[i][j][x^grid[i][j]]=true;
                    if(j>0 && dp[i][j-1][x])dp[i][j][x^grid[i][j]]=true;
                }
            }
        }
        for(int x=0;x<1024;x++){
            if(dp[n-1][m-1][x])return x;
        }
        return -1;
    }
};