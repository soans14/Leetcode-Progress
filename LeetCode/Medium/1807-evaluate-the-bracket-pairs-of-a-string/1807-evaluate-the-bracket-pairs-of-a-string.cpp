class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map <string,string> mpp;
        for(auto i:knowledge){
            mpp[i[0]]=i[1];
        }
        string temp;
        bool flag=false;
        int i=0,j=0;
        for(int k=0;k<s.size();k++){
            if(s[k]=='('){
                i=k;
            }
            else if(s[k]==')'){
                j=k;
                flag=true;
            }
            if(flag){
                temp=s.substr(i+1,j-i-1);
                if(knowledge.size()==0){
                    s.replace(i,j-i+1,"?");
                    k-=(j-i);
                }
                else if(mpp.find(temp)!=mpp.end()){
                    s.replace(i,j-i+1,mpp[temp]);
                    k-=(j-i);
                    k+=mpp[temp].size()-1;
                }
                else{
                    s.replace(i,j-i+1,"?");
                    k-=(j-i);
                }
                flag=false;
            }
        }
        return s;
    }
};