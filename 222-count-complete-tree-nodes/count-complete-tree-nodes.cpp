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
    int calcLeftHeight(TreeNode* node)
    {
        int h=0;
        while(node)
        {
            h++;
            node = node->left;
        }
        return h;
    }
    int calcRightHeight(TreeNode* node)
    {
        int h=0;
        while(node)
        {
            h++;
            node = node->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) 
    {
        int ans = 0;
        if(root == NULL) return ans;

        int lh = calcLeftHeight(root);
        int rh = calcRightHeight(root);

        if(lh==rh) return (1<<lh)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};