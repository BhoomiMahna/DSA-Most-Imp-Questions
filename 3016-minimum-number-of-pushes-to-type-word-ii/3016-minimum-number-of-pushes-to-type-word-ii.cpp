class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>freq;
        for(int i=0;i<word.size();i++){
            freq[word[i]]++;
        }
        vector<int>f;
        for(auto it:freq){
            f.push_back(it.second);
        }
        sort(f.rbegin(),f.rend());
        int ans=0;
        for(int i=0;i<f.size();i++){
            ans+=f[i]*(i/8+1);
        }
        return ans;
    }
};