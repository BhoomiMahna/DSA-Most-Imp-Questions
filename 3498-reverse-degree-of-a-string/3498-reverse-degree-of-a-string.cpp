class Solution {
public:
    int reverseDegree(string s) {
        int total=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            int val=c-'a'+1;
            int revval=27-val;
            total+=((i+1)*revval);
        }
        return total;
    }
};