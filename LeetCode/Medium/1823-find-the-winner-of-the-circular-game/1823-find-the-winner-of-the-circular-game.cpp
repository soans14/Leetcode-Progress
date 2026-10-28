class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        vector<int>::iterator it=v.begin();
        int temp=k;
        while(v.size()>1){
            while(it+temp-1>=v.end()){
                temp-=(v.end()-it);
                it=v.begin();
            }
            v.erase(it+temp-1);
            it=it+temp-1;
            if(it==v.end()){
                it=v.begin();
            }
            temp=k;
        }
        return v[0];
    }
};