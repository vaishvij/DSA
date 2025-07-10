/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_track)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent_track[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent_track[node->right] = node;
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        findParents(root, parent_track);
        queue<TreeNode*> traverse;
        unordered_map<TreeNode*,bool> visited;
        int dist = 0;

        traverse.push(target);
        visited[target] = true;
        while(!traverse.empty())
        {
            int s = traverse.size();
            if(dist == k) break;
            dist++;
            for(int i=0; i<s; i++)
            {
                TreeNode* node = traverse.front();
                traverse.pop();
                if(node->left!=NULL && visited[node->left]==false){
                    traverse.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right!=NULL && visited[node->right]==false){
                    traverse.push(node->right);
                    visited[node->right]=true;
                }
                if(parent_track[node] && visited[parent_track[node]]==false){
                    traverse.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                }
            }
        }
        vector<int> ans;
        while(!traverse.empty())
        {
            TreeNode* node = traverse.front();
            traverse.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};