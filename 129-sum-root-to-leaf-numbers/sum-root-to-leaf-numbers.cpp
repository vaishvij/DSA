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
    void traverse(TreeNode* node, vector<int> &temp, vector<vector<int>> &paths)
    {
        temp.push_back(node->val);

        if(!node->left && !node->right)
        {
            paths.push_back(temp);
        }

        if(node->left) traverse(node->left, temp, paths);
        if(node->right) traverse(node->right, temp, paths);

        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL) return 0;
        vector<int> temp;
        vector<vector<int>> paths;
        traverse(root, temp, paths);
        
        int sum = 0;
        for(auto path : paths)
        {
            int num = 0;
            for(int digit : path)
            {
                num = num*10 + digit;
            }
            sum = sum + num;
        }
        return sum;
    }
};