class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.push_back(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            if(!ans.empty()&&ans.back()>0&&asteroids[i]<0){
                while(!ans.empty()&&abs(ans.back())<abs(asteroids[i])&&ans.back()>0&&asteroids[i]<0){
                    ans.pop_back();
                }
                if(!ans.empty()&&abs(ans.back())==abs(asteroids[i])&&ans.back()>0){
                    ans.pop_back();
                }
                else if(ans.empty()||ans.back()<0){
                    ans.push_back(asteroids[i]);
                }
            }
            else{
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};