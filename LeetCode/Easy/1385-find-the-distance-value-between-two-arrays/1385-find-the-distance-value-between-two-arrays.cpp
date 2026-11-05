class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int count=0,low,mid,high;
        bool flag=true;
        for(int i:arr1){
            low=0;
            high=arr2.size()-1;
            while(low<=high){
                mid=(low+high)/2;
                if(abs(arr2[mid]-i)<=d){
                    flag=false;
                    break;
                }
                else if(arr2[mid]-i>=d){
                    high=mid-1;
                }
                else if(arr2[mid]-i<=(-1*d)){
                    low=mid+1;
                }
            }
            if(flag){
                count++;
            }
            flag=true;
        }
        return count;
    }
};