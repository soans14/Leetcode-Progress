class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long sum=0,even=1,odd=0,count=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2){
                odd++;
                count=(count+even)%mod;
            }
            else{
                even++;
                count=(count+odd)%mod;
            }
        }
        return count;
    }
};