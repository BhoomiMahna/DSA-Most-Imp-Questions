class Solution {
public:
    int dx[2]={0,1};
    int dy[2]={1,0};
    bool valid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n)return true;
        return false;
    }
    
    int find(int row,int col, int m,int n, vector<vector<int>>&dp){
        if(row==m-1 && col==n-1){
            return 1;
        }
        if(dp[row][col]!=-1)return dp[row][col];
        int count=0;
        
        for(int k=0;k<2;k++){
            int nrow=row+dx[k];
            int ncol=col+dy[k];
            if(valid(nrow,ncol,m,n)){
                count+=find(nrow,ncol,m,n,dp);
            }
        }
        return dp[row][col]=count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return find(0,0,m,n,dp);
        
    }
};