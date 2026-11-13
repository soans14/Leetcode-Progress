class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct compare{
            bool operator()(const vector<int>& a,const vector<int>& b){
                return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
            }
        };
        priority_queue<vector<int>,vector<vector<int>>,compare> q;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++){
            if(q.size()<k){
                q.push(points[i]);
            }
            else{
                if(points[i][0]*points[i][0]+points[i][1]*points[i][1]<q.top()[0]*q.top()[0]+q.top()[1]*q.top()[1]){
                    q.pop();
                    q.push(points[i]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};