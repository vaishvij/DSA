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
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL || head->next==NULL) return nullptr;
        map<ListNode*,int> visited;
        ListNode* temp = head;
        while(temp)
        {
            if(visited.count(temp) != 0)
            {
                return temp;
            }
            visited[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
    }
};