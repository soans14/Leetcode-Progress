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
    vector<int> rightSideView(TreeNode* root) {
        struct TreeNode* temp;
        int size;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            size=q.size();
            while(size){
                temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                if(size==1){
                    ans.push_back(temp->val);
                }
                size--;
            }
        }
        return ans;
    }
};