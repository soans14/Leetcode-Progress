class Solution {
public:
    long long sum(vector<int>& piles,int div){
        long long total=0;
        for(int i:piles){
            total+=ceil((double)i/div);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {   
        long long low=1,high=*max_element(piles.begin(),piles.end()),mid;
        while(low<=high){
            mid=(low+high)/2;
            if(sum(piles,mid)<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};