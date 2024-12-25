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
    ListNode* deleteKthNode(ListNode* &head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        if(head==NULL) return NULL;
        int count = 0;
        if(k==1){
            head = head->next;
            free(temp);
            return head;
        }
        while(temp !=NULL){
            count++;
            if(count == k){
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