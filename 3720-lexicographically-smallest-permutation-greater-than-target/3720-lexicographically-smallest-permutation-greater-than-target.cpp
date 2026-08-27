class Solution {
public:
    string ans = "";

    bool backtrack(string &s, string &target, vector<int>& freq, int idx) {

        if(idx == target.size()) {
            return false;
        }
        int x = target[idx] - 'a';
        if(freq[x] > 0) {
            freq[x]--;

            if(backtrack(s, target, freq, idx + 1))
                return true;

            freq[x]++;
        }
        for(int j = x + 1; j < 26; j++) {

            if(freq[j] > 0) {

                ans = target.substr(0, idx);
                ans += char('a' + j);

                freq[j]--;
                for(int k = 0; k < 26; k++) {
                    while(freq[k] > 0) {
                        ans += char('a' + k);
                        freq[k]--;
                    }
                }

                return true;
            }
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        backtrack(s, target, freq, 0);

        return ans;
    }
};