class Solution {
public:
    string smallestPalindrome(string s) {
        /* aabbbcc
         ab
        */
        sort(s.begin(),s.end());
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string ans;
        vector<char>odd;
        for(auto it:mp){
            int div=it.second/2;
            int rem=it.second%2;
            
            while(div--){
                ans+=it.first;
            }
            if(rem!=0){
                odd.push_back(it.first);
            }
        }
        string res=ans;
        reverse(ans.begin(),ans.end());
        if(!odd.empty())res+=odd[0];
        res+=ans;
        return res;
    }
};