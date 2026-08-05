class Solution {
public:
    vector<int>bug;
    void findbugs(int node, vector<bool>&vis,vector<vector<int>>&adj){
        vis[node]=true;
        bug.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]]){
                findbugs(adj[node][i],vis,adj);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            adj[u].push_back(v);
        }
        vector<bool>vis(n,false);
        findbugs(k,vis,adj);
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            if(!vis[u] && vis[v]){
                vector<int>ans;
                for(int j=0;j<n;j++){
                    ans.push_back(j);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};