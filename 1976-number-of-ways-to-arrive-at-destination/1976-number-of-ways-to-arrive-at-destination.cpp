class Solution {
public:
    vector<long long>dp;
    int mod=1e9+7;
    int find(int node,int n, vector<vector<pair<int,int>>>& adj,vector<long long>&dist){
        if(node==n-1){
            return 1;
        }
        if(dp[node]!=-1)return dp[node];
        long long ways=0;
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i].first;
            int t=adj[node][i].second;
            if(dist[node]+t==dist[neigh]){
               ways=(ways+find(neigh,n,adj,dist))%mod;
            }
        }
        return dp[node]=ways;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int t=roads[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long>dist(n,LLONG_MAX);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            long long time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dist[node]<time)continue;

            for(int i=0;i<adj[node].size();i++){
                int neigh=adj[node][i].first;
                int t=adj[node][i].second;
                if(dist[neigh]>time+t){
                    dist[neigh]=time+t;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        dp.assign(n,-1);
        return find(0,n,adj,dist);

    }
};