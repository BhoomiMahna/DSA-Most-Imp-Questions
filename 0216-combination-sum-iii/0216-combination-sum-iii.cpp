class Solution {
public:
    vector<vector<int>>res;
    void find(int idx, int cursum,vector<int>&ans,int k,int n){
        if(cursum==n && ans.size()==k){
            res.push_back(ans);
            return;
        }
        if(cursum>n || ans.size()>k){
            return;
        }
        for(int i=idx;i<10;i++){
            ans.push_back(i);
            find(i+1,cursum+i,ans,k,n);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        find(1,0,ans,k,n);
        return res;

    }
};