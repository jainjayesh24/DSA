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

// Time Complexity:O(1) - The function performs a constant number of operations regardless of the size of the linked list
// Space Complexity:O(1) - The function uses a fixed amount of space for variables, independent of the input size

class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if(head==NULL) return head;
        ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
};