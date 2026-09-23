class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid,minimum=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[low]<=nums[mid]){
                minimum=min(minimum,nums[low]);
                low=mid+1;
            }
            else{
                high=mid-1;
                minimum=min(minimum,nums[mid]);
            }
        }
        return minimum;
    }
};