class Solution {
public:
    const int mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>pos;
        vector<int>dig;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                pos.push_back(i);
                dig.push_back(s[i]-'0');
            }
        }
        int m=dig.size();
        vector<long long>prefixsum(m+1,0);
        vector<long long>prefixnum(m+1,0);
        vector<long long>powers(m+1,1);
        for(int i=0;i<m;i++){
            prefixsum[i+1]=prefixsum[i]+dig[i];
            prefixnum[i+1]=(prefixnum[i]*10 +dig[i])%mod;
            powers[i+1]=(powers[i]*10)%mod;
        }
        for(auto &q:queries){
            int l=q[0]; int r=q[1];
            int L=lower_bound(pos.begin(),pos.end(),l)-pos.begin();
            int R=upper_bound(pos.begin(),pos.end(),r)-pos.begin()-1;
            if(L>R){
                ans.push_back(0);
                continue;
            }
            long long sum=prefixsum[R+1]-prefixsum[L];
            long long no=(prefixnum[R+1]-(prefixnum[L]*powers[R-L+1])%mod+mod)%mod;
            ans.push_back((no*sum)%mod);
        }
        return ans;
    }
};