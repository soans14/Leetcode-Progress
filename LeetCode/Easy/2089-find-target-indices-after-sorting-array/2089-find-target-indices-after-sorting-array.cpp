class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        while(low<nums.size()&&nums[low]==target){
            ans.push_back(low);
            low++;
        }
        return ans;
    }
};