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
    void deleteNode(ListNode* node) 
    {
        ListNode *last;
        while(node->next != NULL)
        {
            last = node;
            node->val = node->next->val;
            node = node->next;
        }
        last->next = NULL;
        delete node;
    }
};