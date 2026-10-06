class Solution {
public:
    int max_ele(vector<vector<int>>& mat,int col){
        int ele=0,index=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>ele){
                ele=max(ele,mat[i][col]);
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0,high=mat[0].size()-1,mid,midrow,left,right;
        while(low<=high){
            mid=(low+high)/2;
            midrow=max_ele(mat,mid);
            left=mid-1>-1?mat[midrow][mid-1]:-1;
            right=mid+1<mat[0].size()?mat[midrow][mid+1]:-1;
            if(mat[midrow][mid]>right&&mat[midrow][mid]>left){
                return {midrow,mid};
            }
            else if(mat[midrow][mid]>right){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};