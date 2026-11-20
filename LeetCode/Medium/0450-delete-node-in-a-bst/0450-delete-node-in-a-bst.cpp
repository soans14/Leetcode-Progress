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
    TreeNode* deleteNode(TreeNode* root, int key) {
        bool flag=true;
        TreeNode* del=new TreeNode();   
        TreeNode* temp=root; 
        TreeNode* prevroot=new TreeNode(0,root,NULL);
        TreeNode* prev=prevroot;    
        if(!root){
            return root;
        }
        while(temp->val!=key){
            if(temp->val>key){
                if(temp->left==NULL){
                    return root;
                }
                else{
                    prev=temp;
                    flag=true;
                    temp=temp->left;
                }
            }
            else{
                if(temp->right==NULL){
                    return root;
                }
                else{
                    prev=temp;
                    flag=false;
                    temp=temp->right;
                }
            }
        }
        del=temp;
        if(temp->left==NULL&&temp->right==NULL){
            if(flag){
                prev->left=NULL;
            }
            else{
                prev->right=NULL;
            }
        }
        else if(temp->left==NULL){
            if(flag){
                prev->left=temp->right;
            }
            else{
                prev->right=temp->right;
            }
        }
        else if(temp->right==NULL){
            if(flag){
                prev->left=temp->left;
            }
            else{
                prev->right=temp->left;
            }
        }
        else{
            if(flag){
                prev->left=temp->left;
                temp=del->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                temp->right=del->right;
            }
            else{
                prev->right=temp->right;
                temp=del->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                temp->left=del->left;
            }
        }
        return prevroot->left;
    }
};