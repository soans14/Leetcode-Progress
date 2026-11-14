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
    bool isValidBST(TreeNode* root) {
        TreeNode* temp=root;
        bool flag=true;
        int prev;
        temp=root;
        stack<TreeNode*> st;
        while(true){
            if(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                temp=st.top();
                st.pop();
                if(flag){
                    prev=temp->val;
                    flag=false;
                }
                else{
                    if(temp->val<=prev){
                        return false;
                    }
                    else{
                        prev=temp->val;
                    }
                }
                temp=temp->right;
            }
        }
        return true;
    }
};