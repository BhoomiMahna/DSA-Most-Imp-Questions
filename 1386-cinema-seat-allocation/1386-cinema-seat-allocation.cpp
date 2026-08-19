class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>mpp;
        for(auto it:reservedSeats){
            mpp[it[0]]=(1<<it[1]) | mpp[it[0]];
        }
        int cnt=2*n;
        for(auto it:mpp){
            int key=it.first;
            int mask=it.second;
            bool left=(!(mask & (1<<2))) && (!(mask & (1<<3))) && (!(mask & (1<<4))) && (!(mask & (1<<5)));
            bool middle=(!(mask & (1<<4))) && (!(mask & (1<<5))) && (!(mask & (1<<6))) && (!(mask & (1<<7)));
            bool right=(!(mask & (1<<6))) && (!(mask & (1<<7))) && (!(mask & (1<<8))) && (!(mask & (1<<9)));
            if(left && right) cnt+=0;
            else if(left  || right || middle) cnt--;
            else cnt-=2;
        }
        return cnt;
    }
};