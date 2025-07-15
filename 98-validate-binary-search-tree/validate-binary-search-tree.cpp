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
    void traverse(TreeNode* node, vector<int> &v)
    {
        if(node==NULL) return;

        traverse(node->left, v);
        v.push_back(node->val);
        traverse(node->right, v);
    }
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL) return true;
        vector<int> v;
        traverse(root, v);
        int flag=0;
        for(int i=0; i<v.size()-1; i++)
        {
            if(v[i] >= v[i+1]){
                flag++;
                break;
            }
        }
        if(flag!=0) return false;
        else return true;
    }
};