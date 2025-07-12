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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        TreeNode* node = root;
        TreeNode* ans;
        while(node)
        {
            if(node->val > val) node = node->left;
            else if(node->val < val) node = node->right;
            else{
                ans = node;
                break;
            }
        }
        return ans;
    }
};