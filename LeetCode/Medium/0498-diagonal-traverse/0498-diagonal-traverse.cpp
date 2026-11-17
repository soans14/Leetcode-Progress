class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool dir=true;
        int i=0,j=0,m=mat.size(),n=mat[0].size(),count=0;
        vector<int> ans;
        while(count!=m*n){
            if(dir){
                while(i>=0&&j<n){
                    ans.push_back(mat[i][j]);
                    count++;
                    i--;
                    j++;
                }
                i++;
                if(j==n){
                    j--;
                    i++;
                }
                dir=false;
            }
            else{
                while(i<m&&j>=0){
                    ans.push_back(mat[i][j]);
                    count++;
                    i++;
                    j--;
                }
                j++;
                if(i==m){
                    j++;
                    i--;
                }
                dir=true;
            }
        }
        return ans;
    }
};