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
    ListNode* deleteNodeWithValueX(ListNode* &head, int X) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        if(head==NULL) return NULL;
        if(head->val==X){
            head = head->next;
            free(temp);
            return head;
        }
        while(temp !=NULL){
            if(temp->val==X){
                prev->next = temp->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};