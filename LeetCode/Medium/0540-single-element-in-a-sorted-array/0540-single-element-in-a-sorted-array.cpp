class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid;
        if(nums.size()==1){
            return nums[0];
        }
        while(low<=high){
            mid=(low+high)/2;
            if(mid==0){
                if(nums[mid+1]!=nums[mid]){
                    break;
                }
            }
            else if(mid==nums.size()-1){
                if(nums[mid-1]!=nums[mid]){
                    break;
                }
            }
            else if(nums[mid-1]!=nums[mid]&&nums[mid+1]!=nums[mid]){
                break;
            }
            else if(nums[mid-1]!=nums[mid]){
                if((high-mid-1)%2==0){
                    high=mid-1;
                }
                else{
                    low=mid+2;
                }
            }
            else if(nums[mid+1]!=nums[mid]){
                if((mid-low+1)%2==1){
                    high=mid-2;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return nums[mid];
    }
};