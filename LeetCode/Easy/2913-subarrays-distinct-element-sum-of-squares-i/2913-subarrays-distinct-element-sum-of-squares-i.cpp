class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long sum=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(mpp.find(nums[j])==mpp.end()){
                    mpp[nums[j]]++;
                }
                sum+=(mpp.size()*mpp.size());
            }
            mpp.clear();
        }
        return sum;
    }
};