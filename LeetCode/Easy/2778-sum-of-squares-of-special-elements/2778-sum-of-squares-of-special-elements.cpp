class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            n%(i+1)?sum+=0:sum+=(nums[i]*nums[i]);
        }
        return sum;
    }
};