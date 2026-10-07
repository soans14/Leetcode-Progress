class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c=0,s=0;
        for(int i:students){
            if(i==0){
                c++;
            }
            else{
                s++;
            }
        }
        for(int i:sandwiches){
            if(i==0){
                if(c==0&&s>0){
                    return s;
                }
                c--;
            }
            else{
                if(s==0&&c>0){
                    return c;
                }
                s--;
            }
        }
        return 0;
    }
};