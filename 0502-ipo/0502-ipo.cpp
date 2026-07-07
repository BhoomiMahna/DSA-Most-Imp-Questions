class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>combine;
        for(int i=0;i<profits.size();i++){
            combine.push_back({profits[i],capital[i]});
        }
        sort(combine.begin(),combine.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
        });
        priority_queue<int>pq;
        int i=0;
        int n=profits.size();
        while(k--){
            while(i<n && combine[i].second<=w){
                pq.push({combine[i].first});
                i++;
            }
            if(pq.empty())break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};