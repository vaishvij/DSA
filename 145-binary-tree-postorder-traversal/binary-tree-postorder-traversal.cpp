/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        if(root==NULL) return ans;

        while(!st.empty() || node!=NULL)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                TreeNode* temp = st.top();
                node = temp->right;
                if(node == NULL)
                {
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty() && temp==st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    node = temp->right;
                }
            }
        }
        return ans;
    }
};