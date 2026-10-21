class Solution {
public:
    int minOperations(string s) {
        int ans=0,n=s.size();
        char mn=s[0],mx=s[0];
        bool flag=false,dup=false;
        if(n==2){
            if(s[0]>s[1]){
                ans=-1;
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(s[i-1]>s[i]){
                    flag=true;
                }
                mn=min(mn,s[i]);
                mx=max(mx,s[i]);
            }
            if(flag){
                if(mn==s[0]||mx==s[n-1]){
                    ans=1;
                }
                else if(mx==s[0]&&mn==s[n-1]){
                    for(int i=1;i<n-1;i++){
                        if(s[i]==mn||s[i]==mx){
                            dup=true;
                        }
                    }
                    if(dup){
                        ans=2;
                    }
                    else{
                        ans=3;
                    }
                }
                else{
                    ans=2;
                }
            }
        }
        return ans;
    }
};