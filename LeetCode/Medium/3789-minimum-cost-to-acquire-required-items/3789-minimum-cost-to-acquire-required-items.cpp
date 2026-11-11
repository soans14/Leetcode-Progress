class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(cost1+cost2>=costBoth){
            if(cost1>=costBoth&&cost2>=costBoth){
                ans=1LL*costBoth*max(need1,need2);
            }
            else if((cost1>=costBoth||cost2>=costBoth)||(need1==need2)){
                ans=1LL*costBoth*min(need1,need2);
                if((need1>need2&&cost1<costBoth)||(need1<need2&&cost2<costBoth)){
                    ans+=1LL*(need1>need2?cost1:cost2)*(abs(need1-need2));
                }
                else{
                    ans+=1LL*costBoth*abs(need1-need2);
                }
            }
            else{
                ans=1LL*costBoth*min(need1,need2)+1LL*(need1>need2?cost1:cost2)*(abs(need1-need2));
            }
        }
        else{
            ans=1LL*cost1*need1+1LL*cost2*need2;
        }
        return ans;
    }
};