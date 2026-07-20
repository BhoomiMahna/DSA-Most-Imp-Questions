class Solution {
public:
    int r,c;
    void shift(vector<vector<int>>& grid, int i,int j){
        while(i<j){
            swap(grid[i/c][i%c],grid[j/c][j%c]);
            i++;
            j--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0)return grid;
        r=grid.size(); 
        c=grid[0].size();
        int n=r*c;
        k%=n;
        if(k==0)return grid;
        shift(grid,0,n-1);
        shift(grid,0,k-1);
        shift(grid,k,n-1);
        return grid;

    }
};