class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string temp;
        int start,end;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(st.empty()){
                    start=i;
                }
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    end=i;
                    temp=s.substr(start+1,end-start-1);
                    s.replace(start,end-start+1,temp);
                    i-=2;
                }
            }
        }
        return s;
    }
};