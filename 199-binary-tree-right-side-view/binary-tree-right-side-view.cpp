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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        map<int,int> mp;
        if(root==NULL) return ans;

        q.push({root,0});
        while(!q.empty())
        {
            auto element = q.front();
            TreeNode* node = element.first;
            int level = element.second;
            q.pop();
            mp[level] = node->val;
            if(node->left != NULL) q.push({node->left, level+1});
            if(node->right != NULL) q.push({node->right, level+1});
        }
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};