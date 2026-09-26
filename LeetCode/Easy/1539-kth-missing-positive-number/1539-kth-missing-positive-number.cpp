class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i,ans;
        if(k<arr[0]){
            return k;
        }
        k-=(arr[0]-1);
        for(i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]>k){
                break;
            }
            k-=(arr[i]-arr[i-1]-1);
        }

        return arr[i-1]+k;
    }
};