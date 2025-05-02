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
    bool isPalindrome(ListNode* head) 
    {
        ListNode* temp = head;
        vector<int> v;
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        for(int i=0; i<n; i++)
        {
            if(v[i] != v[n-i-1])
            {
                return false;
                break;
            }
        }
        return true;
    }
};