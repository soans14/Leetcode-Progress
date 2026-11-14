class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> sum(nums.size()+1,0);
        int minsum=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum[i+1]=sum[i]+nums[i];
        }
        while(l<=r){
            for(int i=0+l-1;i<nums.size();i++){
                if(sum[i+1]-sum[i+1-l]>0){
                    minsum=min(minsum,sum[i+1]-sum[i+1-l]);
                }
            }
            l++;
        }
        return minsum!=INT_MAX?minsum:-1;
    }
};