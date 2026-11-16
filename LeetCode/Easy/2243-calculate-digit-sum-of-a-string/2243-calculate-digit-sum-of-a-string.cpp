class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size(),i=0,sum=0,count=0,temp=0;
        while(n>k){
            for(int j=0;j<n;j++){
                sum+=(s[j]-'0');
                count++;
                if(count==k){
                    if(sum<10){
                        s[i]=(sum+'0');
                        i++;
                    }
                    else{
                        temp=i;
                        while(sum>0){
                            s[i]=(sum%10)+'0';
                            sum/=10;
                            i++;
                        }
                        reverse(s.begin()+temp,s.begin()+i);
                    }
                    count=sum=0;
                }
            }
            if(count>0&&sum<10){
                s[i]=(sum+'0');
                i++;
            }
            else if(count>0&&sum>=10){
                temp=i;
                while(sum>0){
                    s[i]=(sum%10)+'0';
                    sum/=10;
                    i++;
                }
                reverse(s.begin()+temp,s.begin()+i);
            }
            count=sum=0;
            n=i;
            i=0;
        }
        s.erase(s.begin()+n,s.end());
        return s;
    }
};