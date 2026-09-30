class Solution {
public:
    int count(vector<int>& nums,int target){
        int count=0,sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>target){
                return INT_MAX;
            }
            if(sum+nums[i]<=target){
                sum+=nums[i];
            }
            else{
                sum=0;
                count++;
                i--;
            }
        }
        if(sum){
            count++;
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0,minimum=INT_MAX;
        for(int i:nums){
            sum+=i;
            minimum=min(minimum,i);
        }
        int low=minimum,high=sum,mid,ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(count(nums,mid)<=k){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};