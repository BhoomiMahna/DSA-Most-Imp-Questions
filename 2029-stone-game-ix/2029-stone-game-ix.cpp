class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int modd[3]={0,0,0};
        for(int i=0;i<stones.size();i++){
            modd[stones[i]%3]++;
        }
        if(modd[0]%2==0){
            return modd[1]>0 && modd[2]>0;
        }
        return abs(modd[1]-modd[2])>2;
    }
};