/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL) return head;
        ListNode* temp = head;
        int len=0;
        while(temp)
        {
            len++;
            temp=temp->next;
        }

        int ind = len-n;

        if(len==1 && n==1)
        {
            delete head;
            return nullptr;
        }

        if(n == len)
        {
            ListNode *newhead = head->next;
            delete head;
            return newhead;
        }

        ListNode *curr = head->next, *prev = head;
        int i=1;
        while(curr)
        {
            if(i == ind)
            {
                prev->next = curr->next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        return head;
    }
};