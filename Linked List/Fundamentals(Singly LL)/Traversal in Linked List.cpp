/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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

// Time Complexity:O(n) where n is the number of nodes in the linked list due to traversal
// Space Complexity:O(n) for storing the node values in the vector
class Solution {
public:
    vector<int> LLTraversal(ListNode *head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp->next!=nullptr){
            ans.push_back(temp->val);
            temp= temp->next;
        }
        ans.push_back(temp->val);
        return ans;

    }
};