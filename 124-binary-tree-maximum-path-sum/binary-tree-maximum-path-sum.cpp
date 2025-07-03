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
    int maxSum(TreeNode* node, int &sum)
    {
        if(node == NULL) return 0;

        int ls = max(0,maxSum(node->left,sum));
        int rs = max(0,maxSum(node->right,sum));
        sum = max(sum, node->val+ls+rs);
        return max(ls,rs) + node->val;
    }
    int maxPathSum(TreeNode* root) 
    {
        int sum = INT_MIN;
        maxSum(root,sum);
        return sum;
    }
};