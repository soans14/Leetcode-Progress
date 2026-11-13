class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rect1=(abs(ax1-ax2)*abs(ay1-ay2)),rect2=(abs(bx1-bx2)*abs(by1-by2)),x=max(ax1,bx1)<min(ax2,bx2)?min(ax2,bx2)-max(ax1,bx1):0,y=max(ay1,by1)<min(ay2,by2)?min(ay2,by2)-max(ay1,by1):0;
        return rect1+rect2-(x*y);
    }
};