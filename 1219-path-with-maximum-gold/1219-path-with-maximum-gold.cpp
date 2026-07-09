class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int n,m;
    
    bool valid(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m)return true;
        return false;
    }
    
    int dfs(int x,int y,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        vis[x][y]=1;
        int ans=0;
        for(int k=0;k<4;k++){
            int newx=x+dx[k];
            int newy=y+dy[k];
            if(valid(newx,newy) && !vis[newx][newy] && grid[newx][newy]!=0){
                ans=max(ans,dfs(newx,newy,grid,vis));
            }
        }
        vis[x][y]=0;
        return grid[x][y]+ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int res=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    res=max(res,dfs(i,j,grid,vis));
                }
            }
        }
        return res;
    }
};