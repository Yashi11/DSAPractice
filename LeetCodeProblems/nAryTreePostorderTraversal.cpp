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
// TRIVIAL RECURSIVE METHOD
    //  void help(Node* root,vector<int>& ans)
    // {
    //     if(root==NULL) return;
    //     for(auto child:root->children)
    //     {
    //         help(child,ans);
    //     }
    //     ans.push_back(root->val);
    // }
    // vector<int> postorder(Node* root) {
    //     vector<int> ans;
    //     help(root,ans);
    //     return ans;
    // }

// ITTERATIVE METHOD
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* curr =st.top();
            st.pop();
            ans.push_back(curr->val);
            for(int i=0;i<curr->children.size();i++)
            {
                st.push(curr->children[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};