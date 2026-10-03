class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<pair<char, int>> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push({'(', i});
            } else if (s[i] == ')') {
                if (!st.empty() && st.top().first == '(') {
                    st.pop();
                } else {
                    st.push({')', i});
                }
            }
        }
        int idx = n;
        int ans = 0;
        while (!st.empty()) {
            int remidx = st.top().second;
            st.pop();
            ans = max(ans, idx - remidx - 1);
            idx = remidx;
        }
        ans = max(ans, idx);
        return ans;
    }
};