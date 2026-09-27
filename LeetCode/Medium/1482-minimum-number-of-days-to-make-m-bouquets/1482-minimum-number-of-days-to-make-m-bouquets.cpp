class Solution {
public:
    long long bouquets(vector<int>& arr,int k,int day){
        long long count=0,bouquet=0;
        for(int i:arr){
            if(i<=day){
                count++;
            }
            else{
                bouquet+=(count/k);
                count=0;
            }
        }
        bouquet+=(count/k);
        return bouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long low=*min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end()),mid,ans=INT_MAX;
        if((long long)m*k>bloomDay.size()){
            return -1;
        }
        while(low<=high){
            mid=(low+high)/2;
            if(bouquets(bloomDay,k,mid)>=m){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};