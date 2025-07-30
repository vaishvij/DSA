/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        queue<Node*> q;

        if(root == NULL) return ans;

        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            vector<int> temp;
            for(int i=0; i<s; i++)
            {
                Node* nod = q.front();
                temp.push_back(nod->val);
                q.pop();
                for(auto child : nod->children)
                {
                    q.push(child);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};