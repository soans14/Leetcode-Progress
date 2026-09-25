class Solution {
public:
    int mySqrt(int x) {
        long long low=0,high=x,mid,ans=0;
        while(low<=high){
            mid=(low+high)/2;
            if(mid*mid<=x){
                ans=max(ans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};