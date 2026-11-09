/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        struct Node* temp= new Node();
        int size;
        if(root==NULL||(root->left==NULL&&root->right==NULL)){
            return root;
        }
        queue<struct Node*> q;
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
                    temp->next=NULL;
                }
                else{
                    temp->next=q.front();
                }
                size--;
            }
        }
        return root;
    }
};