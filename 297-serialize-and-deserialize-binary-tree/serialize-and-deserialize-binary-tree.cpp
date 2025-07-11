/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string str = "";
        queue<TreeNode*> q;
        if(root==NULL) return str;
        
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if (cur == NULL) {
                str.append("#,");
            } 
            else {
                str.append(to_string(cur->val) + ",");
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.empty()) return nullptr;
        TreeNode* root;
        stringstream s(data);
        string str;
        getline(s,str,',');
        root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#") cur->left = NULL;
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                cur->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#") cur->right = NULL;
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                cur->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));