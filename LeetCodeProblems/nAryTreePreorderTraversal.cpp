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
    void helper(Node* root,vector<int>& ans)
    {
        if(root == NULL) return;
        ans.push_back(root->val);
        vector<Node*> children=root->children;
        for(int i=0;i<children.size();i++)
        {
            helper(children[i],ans);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};