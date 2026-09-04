class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>prefixmax;
        vector<int>suffixmin;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            prefixmax.push_back(maxi);
            mini=min(mini,nums[nums.size()-1-i]);
            suffixmin.push_back(mini);
        }
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(prefixmax[i]-suffixmin[nums.size()-1-i]<=k){
            ans=i;
            break;
            }
        }
        if(ans==INT_MAX){
            return-1;
        }
        else{
            return ans;
        }
    }
};