class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>>time(n);
        for(int i=0;i<n;i++){
            time[i].first=position[i];
            time[i].second=(double)(target-position[i])/speed[i];
        }
        sort(time.rbegin(),time.rend());
        int fleet=1;
        double prevtime=time[0].second;
        for(int i=1;i<n;i++){
            if(time[i].second>prevtime){
                fleet++;
                prevtime=time[i].second;
            }
        }
        return fleet;
    }
};