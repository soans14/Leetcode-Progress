class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int ma1=0,ma2=0,ml1=0,ml2=0,da1=0,da2=0,dl1=0,dl2=0;
        ma1=arriveAlice[0]-'0';
        ma1=ma1*10+(arriveAlice[1]-'0');
        ma2=arriveBob[0]-'0';
        ma2=ma2*10+(arriveBob[1]-'0');
        ml1=leaveAlice[0]-'0';
        ml1=ml1*10+(leaveAlice[1]-'0');
        ml2=leaveBob[0]-'0';
        ml2=ml2*10+(leaveBob[1]-'0');
        da1=arriveAlice[3]-'0';
        da1=da1*10+(arriveAlice[4]-'0');
        da2=arriveBob[3]-'0';
        da2=da2*10+(arriveBob[4]-'0');
        dl1=leaveAlice[3]-'0';
        dl1=dl1*10+(leaveAlice[4]-'0');
        dl2=leaveBob[3]-'0';
        dl2=dl2*10+(leaveBob[4]-'0');
        unordered_map<int,int> mpp={{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
        int currM,currD,leavM,leavD,count=0;
        if(ma1>ma2){
            currM=ma1;
            currD=da1;
        }
        else if(ma1<ma2){
            currM=ma2;
            currD=da2;
        }
        else{
            currM=ma1;
            currD=max(da1,da2);
        }
        if(ml1<ml2){
            leavM=ml1;
            leavD=dl1;
        }
        else if(ml1>ml2){
            leavM=ml2;
            leavD=dl2;
        }
        else{
            leavM=ml1;
            leavD=min(dl1,dl2);
        }
        if(currM<leavM){
            count+=(mpp[currM]-currD+1);
            currM++;
            currD=1;
        }
        while(currM<leavM){
            count+=(mpp[currM]);
            currM++;
        }
        if(currM==leavM&&currD<=leavD){
            count+=(leavD-currD+1);
        }
        return count;
    }
};