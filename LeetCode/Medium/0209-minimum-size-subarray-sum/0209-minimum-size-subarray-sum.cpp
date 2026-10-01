class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,ans=INT_MAX;
        long long sum=nums[0];
        while(i<=j&&j<nums.size()){
            if(sum<target){
                j++;
                if(j==nums.size()){
                    break;
                }
                sum+=nums[j];
            }
            else{
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};