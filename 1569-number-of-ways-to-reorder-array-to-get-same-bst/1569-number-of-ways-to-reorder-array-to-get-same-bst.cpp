class Solution {
public:
    const int mod=1e9+7;
    long long combination[1001][1001];
    int solve(vector<int>&nums){
        int n=nums.size();
        if(n<=2)return 1;
        vector<int>left,right;
        int root=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]<root){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }
        long long leftways=solve(left);
        long long rightways=solve(right);
        long long interleaveways=combination[n-1][left.size()];
        return interleaveways*leftways%mod* rightways%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<=n;i++){
            combination[i][0]=combination[i][i]=1;
            for(int j=1;j<i;j++){
                combination[i][j]=(combination[i-1][j-1]+combination[i-1][j])%mod;
            }
        }
        return (solve(nums)-1 +mod)%mod;
    }
};