class Solution {
public:
    bool isValid(string s) {
        int b1=0,b2=0,b3=0;
        vector<char> stack;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                stack.push_back(s[i]);
            }
            else if(s[i]==')'){
                if(!stack.empty()&&stack.back()=='('){
                    stack.pop_back();
                }
                else return false;
            }
            else if(s[i]=='}'){
                if(!stack.empty()&&stack.back()=='{'){
                    stack.pop_back();
                }
                else return false;
            }
            else if(s[i]==']'){
                if(!stack.empty()&&stack.back()=='['){
                    stack.pop_back();
                }
                else return false;
            }
        }
        return stack.empty()?true:false;
    }
};