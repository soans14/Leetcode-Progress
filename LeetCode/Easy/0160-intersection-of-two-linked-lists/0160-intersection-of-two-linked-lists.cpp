/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        struct ListNode* temp1=headA;
        struct ListNode* temp2=headB;
        bool flag1=true,flag2=true;
        while(temp1!=temp2&&temp1!=NULL&&temp2!=NULL){
            if(flag1&&temp1->next==NULL){
                temp1=headB;
                flag1=false;
            }
            else{
                temp1=temp1->next;
            }
            if(flag2&&temp2->next==NULL){
                temp2=headA;
                flag2=false;
            }
            else{
                temp2=temp2->next;
            }
        }
        return temp1==temp2?temp1:NULL;
    }
};