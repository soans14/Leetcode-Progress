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
class BSTIterator {
public:
    TreeNode* temp=new TreeNode();
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        temp=root;
    }
    
    int next() {
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        temp=st.top();
        st.pop();
        int ans=temp->val;
        temp=temp->right;
        return ans;
    }
    
    bool hasNext() {
        return !st.empty()||(temp!=NULL?true:false);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */