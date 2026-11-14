class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minnum=256,maxnum=-1,mean=0,med,mod=-1;
        long long sum=0;
        int countnum=0,temp=0;
        bool flag;
        for(int i=0;i<count.size();i++){
            if(count[i]>0){
                minnum=min(minnum,(double)i);
                maxnum=max(maxnum,(double)i);
                sum+=((long long)i*count[i]);
                countnum+=(count[i]);
            }
            if(count[i]>temp){
                mod=i;
                temp=count[i];
            }
        }
        mean=(double)sum/countnum;
        temp=0;
        if(countnum%2){
            countnum/=2;
            countnum++;
            flag=true;
        }
        else{
            countnum/=2;
            flag=false;
        }
        for(int i=0;i<count.size();i++){
            temp+=count[i];
            if(flag){
                if(temp>=countnum){
                    med=i;
                    break;
                }
            }
            else{
                if(temp>=countnum+1){
                    med=i;
                    break;
                }
                else if(temp==countnum){
                    med=i;
                    while(temp==countnum){
                        i++;
                        temp+=count[i];
                    }
                    med+=i;
                    med/=2;
                    break;
                }
            }
        }
        return {minnum,maxnum,mean,med,mod};
    }
};