class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        for (string word : words) {
            freq[word]++;
        }

        vector<string> arr;

        for (auto& pair : freq) {
            arr.push_back(pair.first);
        }
        sort(arr.begin(), arr.end(), [&](string& a, string& b) {

            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];   
            }
            return a < b;                
        });
        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};