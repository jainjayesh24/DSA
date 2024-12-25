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
    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
        ListNode* newnode = new ListNode(X);
        if(head==NULL){
            if(K==1){
                head = newnode;
                return head;
            }
            else return NULL;
        }
        if(K==1){
            newnode->next = head;
            head = newnode;
            return head;
        }

        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            if(count == K-1){
                newnode->next = temp->next;
                temp->next = newnode;
            }
            temp =temp->next;
        }
        return head;

    }
};