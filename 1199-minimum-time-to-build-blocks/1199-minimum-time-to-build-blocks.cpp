class Solution {
public:
    bool check(int val,vector<int>&blocks,int split,int n){
        int i=0;
        int worker=1;
        int time=0;
        while(worker && (i+worker<n)){
            while(worker && (time+blocks[i]+split>val)){
                i++;
                worker--;
            }
            time+=split;
            worker*=2;
        }
        return (i+worker>=n) && (time+blocks[i]<=val);
    }
    int minBuildTime(vector<int>& blocks, int split) {
        int n=blocks.size();
        sort(blocks.rbegin(),blocks.rend());
        int low=0, high=INT_MAX;
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(mid,blocks,split,n)){
                high=mid;
            }
            else low=mid+1;
        }
        return low;
    }
};