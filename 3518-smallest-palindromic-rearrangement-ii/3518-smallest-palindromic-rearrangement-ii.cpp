class Solution {
public:
    long long mod = 1e9+7;
    long long pos(vector<int> & alpha , int k){ 
        vector<long long> m;
        long long n =0;
        for(int i : alpha){
            n+=i;
            if(i>=1){
                m.push_back(i);
            }
        }

        long long num =1 ,add=1;
        for(long long i : m){
            for(long long j = 1 ; j<=i; j++){
                num = (num *add);
                add++;
                num/=j;
                if(num >=k){
                    return k;
                }
            }
        }
        return num;
    }
    string smallestPalindrome(string s, int k) {
        string temp ;
        int n = s.length();
        vector<int> alpha(26,0);
        for(int i =0 ; i <n/2 ; i++ ){
            temp.push_back(s[i]);
            alpha[s[i]-'a']++;
        }
        sort(temp.begin(),temp.end());
        
        string res;
        long long tot =0;
        for(int i = 0 ;i < n/2; i++ ){ 
            bool ok = true;
            for(int j =0 ; j<26 ; j++ ){
                if(alpha[j]!=0){
                    alpha[j]--; 
                    int val = pos(alpha,k);
                    tot += val;
                    alpha[j]++; 
                   
                    if(tot >=k){
                        alpha[j]--;
                        tot -= val;
                        res.push_back(j+'a');
                        ok = false;
                        
                        break;
                    }
                    
                }
            }
            
            if(ok){
                return "";
            }
            
            
        }
        
        string t =res;
        reverse(t.begin(),t.end());
        if(n&1){
            res.push_back(s[(n)/2]);
        }
        res +=t;
        return res;
    }
};