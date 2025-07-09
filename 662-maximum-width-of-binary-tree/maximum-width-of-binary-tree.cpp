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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int maxWidth = 0;
        int lvlWidth = 0;
        queue<pair<TreeNode*,long long>> q;
        if(root == NULL) return 0;

        q.push({root,0});
        while(!q.empty())
        {
            int s = q.size();
            long long previd = q.front().second;

            long long startInd = q.front().second;
            long long endInd = q.back().second;
            lvlWidth = endInd - startInd + 1;
            
            for(int i=0; i<s; i++)
            {
                TreeNode* node = q.front().first;
                long long curid = q.front().second - previd;
                q.pop();
                //if(i==0) first=curid;
                //if(i==s-1) last=curid;
                if(node->left) q.push({node->left, 2*curid+1});
                if(node->right) q.push({node->right, 2*curid+2});
            }
            maxWidth = max(maxWidth,lvlWidth);
        }
        return maxWidth;
    }
};