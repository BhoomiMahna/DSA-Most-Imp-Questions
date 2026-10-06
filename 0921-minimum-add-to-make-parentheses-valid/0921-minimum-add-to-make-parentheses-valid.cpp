class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftopen=0,rightopen=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(rightopen==0)leftopen++;
                else rightopen--;
            }
            else{
                rightopen++;
            }
        }
        return abs(rightopen+leftopen);
    }
};