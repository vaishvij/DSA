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
    void traverse(TreeNode* root, vector<int> &store)
    {
        if(root==NULL) return;

        traverse(root->left, store);
        store.push_back(root->val);
        traverse(root->right, store);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> store;
        traverse(root,store);
        sort(store.begin(), store.end());
        return store[k-1];
    }
};