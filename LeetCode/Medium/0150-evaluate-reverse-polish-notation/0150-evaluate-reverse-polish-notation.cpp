class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,b;
        unordered_map<string,int> mpp;
        mpp["+"]=1;
        mpp["-"]=2;
        mpp["*"]=3;
        mpp["/"]=4;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                switch(mpp[tokens[i]]){
                    case 1:
                    st.push(a+b);
                    break;
                    case 2:
                    st.push(a-b);
                    break;
                    case 3:
                    st.push(a*b);
                    break;
                    case 4:
                    st.push(a/b);
                    break;
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};