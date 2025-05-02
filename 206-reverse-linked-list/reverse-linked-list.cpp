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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp = head;
        vector<int> v;
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n=v.size();
        for(int i=0; i<n/2; i++)
        {
            swap(v[i],v[n-i-1]);
        }
        temp = head;
        for(int i=0; i<v.size(); i++)
        {
            temp->val = v[i];
            temp = temp->next;
        }
        return head;
    }
};