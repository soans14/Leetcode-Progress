class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> nge;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge.push_back(-1);
            }
            else{
                nge.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(nge.begin(),nge.end());
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    nums1[i]=nge[j];
                    break;
                }
            }
        }
        return nums1;
    }
};