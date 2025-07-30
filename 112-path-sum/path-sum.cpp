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
    void traverse(TreeNode* node, int &sum, int targetSum, bool &found)
    {
        sum = sum + node->val;

        
        if(!node->left && !node->right && sum != targetSum)
        {
            sum = sum - node->val;
            return;
        }
        else if(!node->left && !node->right && sum == targetSum)
        {
            found = true;
            return;
        }

        if(node->left) traverse(node->left, sum, targetSum, found);
        if(node->right) traverse(node->right, sum, targetSum, found);

        sum = sum - node->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL) return false;
        int sum = 0;
        bool found = false;
        traverse(root,sum,targetSum,found);
        return found;
    }
};