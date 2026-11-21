class Solution {
public:
    void dfs(vector<vector<int>>& children, vector<int>& targets, vector<int>& charToNode, string& str, int node) {
        int cha = str[node] - 'a';
        int prev = charToNode[cha];
        if (prev != -1) targets[node] = prev;
        charToNode[cha] = node;
        for (auto child : children[node]) {
            dfs(children, targets, charToNode, str, child);
        }
        charToNode[cha] = prev;
    }
    int calc(vector<vector<int>>& children, vector<int>& ans, string& str, int node) {
        int sz = 1;
        for (auto child : children[node]) {
            sz += calc(children, ans, str, child);
        }
        ans[node] = sz;
        return sz;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.length();
        vector<vector<int>> children(n, vector<int>(0));
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
        vector<int> charToNode(26, -1);
        vector<int> targets(n, -1);
        dfs(children, targets, charToNode, s, 0);
        for (int i = 0; i < n; ++i) children[i].clear();
        for (int i = 0; i < n; ++i) {
            if (targets[i] != -1) parent[i] = targets[i];
        }
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
        vector<int> ans(n);
        calc(children, ans, s, 0);
        return ans;
    }
};