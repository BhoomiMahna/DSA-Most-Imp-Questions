class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {0,31,59,90,120,151,181,212,243,273,304,334};

        int a1=days[stoi(arriveAlice.substr(0,2))-1]+stoi(arriveAlice.substr(3,2));
        int a2=days[stoi(leaveAlice.substr(0,2))-1]+stoi(leaveAlice.substr(3,2));
        int b1=days[stoi(arriveBob.substr(0,2))-1]+stoi(arriveBob.substr(3,2));
        int b2=days[stoi(leaveBob.substr(0,2))-1]+stoi(leaveBob.substr(3,2));

        int st=a1;
        if(b1>st)st=b1;
        int end=a2;
        if(b2<end)end=b2;

        if(st>end)return 0;
        return end-st+1;
    }
};