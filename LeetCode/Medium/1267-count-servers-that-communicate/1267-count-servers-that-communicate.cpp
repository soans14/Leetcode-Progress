class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count=0,r=grid.size(),c=grid[0].size();
        vector<int> row(r,0);
        vector<int> col(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                    count++;
                }
            }
        }
        for(int i=0;i<r;i++){
            if(row[i]==1){
                for(int j=0;j<c;j++){
                    if(grid[i][j]==1){
                        if(col[j]==1){
                            count--;
                        }
                    }
                }
            }
        }
        return count;
    }
};