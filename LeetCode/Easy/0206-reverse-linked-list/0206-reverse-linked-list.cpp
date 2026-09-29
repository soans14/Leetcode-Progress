/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
            return head;
        }
        else if(head->next->next==NULL){
            head->next->next=head;
            head=head->next;
            head->next->next=NULL;
        }
        else{
            ListNode* prev=head;
            ListNode* temp=head->next;
            ListNode* front=head->next->next;
            head->next=NULL;
            while(front!=NULL){
                temp->next=prev;
                prev=temp;
                temp=front;
                front=front->next;
            }
            temp->next=prev;
            head=temp;
        }
        return head;
    }
};