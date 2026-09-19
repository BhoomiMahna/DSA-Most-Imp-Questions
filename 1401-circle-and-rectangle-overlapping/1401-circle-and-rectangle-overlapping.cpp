class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xp=max(x1,min(xCenter,x2));
        int yp=max(y1,min(yCenter,y2));
        return radius*radius>=pow(xp-xCenter,2)+pow(yp-yCenter,2);
    }
};