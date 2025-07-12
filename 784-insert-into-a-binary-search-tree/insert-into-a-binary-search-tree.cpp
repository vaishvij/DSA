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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode* newnode = new TreeNode(val);
        if (root == NULL) return newnode;

        TreeNode* cur = root;
        while (true) 
        {
            if (val < cur->val) 
            {
                if (!cur->left) {
                    cur->left = newnode;
                    break;
                } 
                else {
                    cur = cur->left;
                }
            } else if(val > cur->val)
            {
                if (!cur->right) {
                    cur->right = newnode;
                    break;
                } 
                else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};