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
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* temp=root;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        int size;
        if(root==NULL){
            return ans;
        }
        q.push(temp);
        while(!q.empty()){
            vector<int> v;
            size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* Node=q.front();
                v.push_back(Node->val);
                if(Node->left!=NULL){
                    q.push(Node->left);
                }
                if(Node->right!=NULL){
                    q.push(Node->right);
                }
                q.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
};