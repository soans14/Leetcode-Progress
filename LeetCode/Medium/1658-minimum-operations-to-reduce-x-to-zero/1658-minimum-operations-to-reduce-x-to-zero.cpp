class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target,sum=0,i=0,j=0,maximum=-1;
        for(int i:nums){
            sum+=i;
        }
        target=sum-x;
        sum=nums[0];
        if(target==0){
            return nums.size();
        }
        while(i<nums.size()&&j<nums.size()){
            if(sum<target){
                j++;
                if(j<nums.size()){
                    sum+=nums[j];
                }
            }
            else if(sum>target){
                if(i<nums.size()){
                    sum-=nums[i];
                    i++;
                }
            }
            else{
                maximum=max(maximum,j-i+1);
                j++;
                if(j<nums.size()){
                    sum+=nums[j];
                }
                if(i<nums.size()){
                    sum-=nums[i];
                    i++;
                }
            }
        }
        if(maximum!=-1){
            maximum=nums.size()-maximum;
        }
        return maximum;
    }
};