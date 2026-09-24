class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int sum,n=nums.size();
        for(int i=0;i<min(n,28);i++){
            sum=0;
            while(nums[i]>0){
                sum+=(nums[i]%10);
                nums[i]/=10;
                if(sum>i){
                    break;
                }
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};