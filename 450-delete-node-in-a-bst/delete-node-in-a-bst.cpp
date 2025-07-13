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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == NULL) return NULL;

        TreeNode* cur = root;
        TreeNode* prev = NULL;

        while (cur && cur->val != key) {
            prev = cur;
            if (key < cur->val) cur = cur->left;
            else if(key > cur->val) cur = cur->right;
        }

        if (!cur) return root; // key not found

        // Case 1: Node has no children (leaf node)
        if (!cur->left && !cur->right) {
            if (cur == root) {
                delete cur;
                return NULL; 
            }
            if (prev->left == cur) prev->left = NULL;
            else prev->right = NULL;
            delete cur;
        }
        // Case 2: Node has one child
        else if (!cur->left || !cur->right) {
            TreeNode* child = (cur->left) ? cur->left : cur->right;
            if (cur == root) {
                delete cur;
                return child;  
            }
            if (prev->left == cur) prev->left = child;
            else prev->right = child;
            delete cur;
        }
            // Case 3: Node has two children
            else {
                TreeNode* succParent = cur;
                TreeNode* succ = cur->right;
                while (succ->left) {
                    succParent = succ;
                    succ = succ->left;
                }
                cur->val = succ->val;

                if (succParent->left == succ)
                    succParent->left = succ->right;
                else
                    succParent->right = succ->right;

                delete succ;
            }

            return root;
    }
};