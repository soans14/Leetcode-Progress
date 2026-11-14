class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int minmove=0,maxmove=0;
        vector<int> v(3);
        v[0]=a;
        v[1]=b;
        v[2]=c;
        sort(v.begin(),v.end());
        a=v[0];
        b=v[1];
        c=v[2];
        if(b-a==1&&c-b==1){
            minmove=0;
        }
        else if(b-a==1||c-b==1||b-a==2||c-b==2){
            minmove=1;
        }
        else{
            minmove=2;
        }
        maxmove+=(b-a-1);
        maxmove+=(c-b-1);
        return {minmove,maxmove};
    }
};