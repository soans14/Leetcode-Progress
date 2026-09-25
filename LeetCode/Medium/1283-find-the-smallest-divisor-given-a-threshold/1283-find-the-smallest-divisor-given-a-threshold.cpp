class Solution {
public:
    int sum(vector<int>& nums,int div){
        int sum=0;
        for(int i:nums){
            sum+=(ceil(i/(double)div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int low=1,high=nums[nums.size()-1],mid,ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(sum(nums,mid)<=threshold){
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