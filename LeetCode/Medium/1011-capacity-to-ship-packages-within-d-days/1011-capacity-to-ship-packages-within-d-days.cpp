class Solution {
public:
    int sum(vector<int>& arr){
        int sum=0;
        for(int i:arr){
            sum+=i;
        }
        return sum;
    }
    int day(vector<int>& arr,int cap){
        int sum=0,count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+sum<=cap){
                sum+=arr[i];
            }
            else{
                count++;
                sum=0;
                i--;
            }
        }
        if(sum){
            count++;
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),high=sum(weights),mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            if(day(weights,mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};