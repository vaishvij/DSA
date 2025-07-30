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
    void traverse(TreeNode* node, int &sum, int targetSum, vector<vector<int>> &ans, vector<int> &temp)
    {
        sum = sum + node->val;
        temp.push_back(node->val);

        if(!node->left && !node->right && sum==targetSum)
        {
            ans.push_back(temp);
        }

        if(node->left) traverse(node->left, sum, targetSum, ans, temp);
        if(node->right) traverse(node->right, sum, targetSum, ans, temp);

        sum = sum - node->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        int sum = 0;
        vector<int> temp;
        traverse(root, sum, targetSum, ans, temp);
        return ans;
    }
};