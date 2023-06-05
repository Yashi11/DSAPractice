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
    void preorder(TreeNode* root,vector<TreeNode*>& preOrder)
    {
        if(root==NULL) return;
        preOrder.push_back(root);
        preorder(root->left,preOrder);
        preorder(root->right,preOrder);

    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
       vector<TreeNode*> preOrder; 
       preorder(root,preOrder);
       root= preOrder[0];
       root->left=NULL;
       
       for(int i=1;i<preOrder.size();i++)
       {
           preOrder[i-1]->right=preOrder[i];
           preOrder[i]->left=NULL;
       }
       preOrder[preOrder.size()-1]->right=NULL;
    }
};