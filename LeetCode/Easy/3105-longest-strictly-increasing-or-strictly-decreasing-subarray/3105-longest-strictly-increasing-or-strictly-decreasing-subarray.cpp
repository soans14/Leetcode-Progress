class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1,tempinc=1,tempdec=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                tempinc++;
                inc=max(inc,tempinc);
                tempdec=1;
            }
            else if(nums[i-1]>nums[i]){
                tempdec++;
                dec=max(dec,tempdec);
                tempinc=1;
            }
            else{
                inc=max(inc,tempinc);
                tempdec=1;
                dec=max(dec,tempdec);
                tempinc=1;
            }
        }
        return max(inc,dec);
    }
};