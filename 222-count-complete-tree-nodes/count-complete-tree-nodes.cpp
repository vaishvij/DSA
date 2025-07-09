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
    int inOrderCount(TreeNode* node, int &ans)
    {
        ans++;
        if(node->left) inOrderCount(node->left, ans);
        if(node->right) inOrderCount(node->right, ans);
        return ans;
    }
    int countNodes(TreeNode* root) 
    {
        int ans = 0;
        if(root == NULL) return ans;
        return inOrderCount(root,ans);
    }
};