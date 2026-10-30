class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges)
            graph[e[0]].push_back({e[1], e[2]});
        vector<int>best(n,k+1);  
        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<>>heap;  
        heap.push({0, 1, 0});
        while (!heap.empty()) {
            auto [d, run, x] = heap.top();
            heap.pop();
            if (run >= best[x]) 
                continue;
            if (x == n - 1)
                return d;
            best[x] = run;
            for (auto [y, w] : graph[x]) {
                int r = labels[y] == labels[x] ? run+1:1;
                if (r < best[y]) 
                    heap.push({d+w,r,y});
            }
        }
        return -1;

    }
};