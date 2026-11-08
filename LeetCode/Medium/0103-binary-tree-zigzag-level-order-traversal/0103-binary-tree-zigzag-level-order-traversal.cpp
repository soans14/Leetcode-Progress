/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<struct TreeNode*> st1;
        stack<struct TreeNode*> st2;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        struct TreeNode* temp=root;
        st1.push(root);
        while(!st1.empty()||!st2.empty()){
            vector<int> v1;
            while(!st1.empty()){
                temp=st1.top();
                v1.push_back(temp->val);
                if(temp->left!=NULL){
                    st2.push(temp->left);
                }
                if(temp->right!=NULL){
                    st2.push(temp->right);
                }
                st1.pop();
            }
            if(!v1.empty()){
                ans.push_back(v1);
            }
            vector<int> v2;
            while(!st2.empty()){
                temp=st2.top();
                v2.push_back(temp->val);
                if(temp->right!=NULL){
                    st1.push(temp->right);
                }
                if(temp->left!=NULL){
                    st1.push(temp->left);
                }
                st2.pop();
            }
            if(!v2.empty()){
                ans.push_back(v2);
            }
        }
        return ans;
    }
};