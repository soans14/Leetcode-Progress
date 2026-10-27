class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string temp(n,' ');
        if(m==1){
            for(int j=0;j<n;j++){
                temp[j]='.';
            }
            ans.push_back(temp);
        }
        else if(n==1){
            for(int j=0;j<m;j++){
                temp=".";
                ans.push_back(temp);
            }
        }
        else{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==m-1){
                        temp[j]='.';
                    }
                    else{
                        if(j==0){
                            temp[j]='.';
                        }
                        else{
                            temp[j]='#';
                        }
                    }
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};