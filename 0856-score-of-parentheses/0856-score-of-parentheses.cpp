class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char>st;
        int count=0;
        int score=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('){
                st.push(c);
                count++;
            }
            else{
                int x=count;
                if(s[i-1]=='('){
                    int j=0;
                    int power=1;
                    while(j!=x-1){
                        power=power*2;
                        j++;
                    }
                    score+=power;
                }
                st.pop();
                count--;
            }
        }
        return score;
    }
};