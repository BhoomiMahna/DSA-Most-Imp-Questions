class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                int temp=image[i][j];
                image[i][j]=image[i][m-1-j];
                image[i][m-1-j]=temp;           
            } 
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                image[i][j]=1-image[i][j];
            }
        }
        return image;
    }
};