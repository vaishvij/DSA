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
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL || head->next==NULL) return false;
        ListNode* temp = head;
        while(temp!=NULL && temp->next!=NULL)
        {
            temp->val = INT_MIN;
            if(temp->next->val == INT_MIN)
            {
                return true;
                break;
            }
            temp = temp->next;
        }
        return false;
    }
};