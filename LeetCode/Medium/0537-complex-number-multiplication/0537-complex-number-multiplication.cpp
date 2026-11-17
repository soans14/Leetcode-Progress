class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1=0,r2=0,c1=0,c2=0,r3=0,c3=0,c=0;
        string ans;
        bool flag=true,negr=false,negc=false;
        for(char i:num1){
            if(flag&&i=='-'){
                negr=true;
            }
            if(flag&&i<='9'&&i>='0'){
                r1*=10;
                r1+=(i-'0');
            }
            else if(i=='+'){
                flag=false;
            }
            if(!flag&&i=='-'){
                negc=true;
            }
            if(!flag&&i<='9'&&i>='0'){
                c1*=10;
                c1+=(i-'0');
            }
        }
        if(negr){
            r1*=-1;
            negr=false;
        }
        if(negc){
            c1*=-1;
            negc=false;
        }
        flag=true;
        for(char i:num2){
            if(flag&&i=='-'){
                negr=true;
            }
            if(flag&&i<='9'&&i>='0'){
                r2*=10;
                r2+=(i-'0');
            }
            else if(i=='+'){
                flag=false;
            }
            if(!flag&&i=='-'){
                negc=true;
            }
            if(!flag&&i<='9'&&i>='0'){
                c2*=10;
                c2+=(i-'0');
            }
        }
        if(negr){
            r2*=-1;
            negr=false;
        }
        if(negc){
            c2*=-1;
            negc=false;
        }
        r3+=r1*r2-c1*c2;
        c3+=c1*r2+r1*c2;
        if(r3==0){
            ans.push_back('0');
        }
        while(r3!=0){
            if(r3<0){
                ans.push_back('-');
                r3*=-1;
            }
            ans.push_back(r3%10+'0');
            r3/=10;
            c++;
        }
        reverse(ans.end()-c,ans.end());
        ans.push_back('+');
        c=0;
        if(c3==0){
            ans.push_back('0');
        }
        while(c3!=0){
            if(c3<0){
                ans.push_back('-');
                c3*=-1;
            }
            ans.push_back(c3%10+'0');
            c3/=10;
            c++;
        }
        reverse(ans.end()-c,ans.end());
        ans.push_back('i');
        return ans;
    }
};