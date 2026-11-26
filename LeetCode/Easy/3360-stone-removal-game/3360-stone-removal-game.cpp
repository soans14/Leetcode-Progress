class Solution {
public:
    bool canAliceWin(int n) {
        bool alice=false;
        int i=10;
        while(n>0&&n>=i){
            n-=i;
            i--;
            alice=alice?false:true;
        }
        return alice;
    }
};