class Solution {
public:
    int maxDepth(string s) {
        int count=0,max_count=-1;
        for(auto i:s){
            if(i=='('){
                count++;
            }
            else if(i==')'){
                count--;
            }
            max_count=max(max_count,count);
        }
        return max_count;
    }
};