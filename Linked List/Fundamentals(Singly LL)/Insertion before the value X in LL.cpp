/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* insertBeforeX(ListNode* &head, int X, int val) {
        if(head==NULL) return NULL;

        if(head->val==X){
            return new ListNode(val,head);
        }
        ListNode* temp = head;
        while(temp->next!=NULL){
            if(temp->next->val==X){
                ListNode* newnode = new ListNode(val,temp->next);
                temp->next = newnode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
