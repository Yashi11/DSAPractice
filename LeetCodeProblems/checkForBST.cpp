class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root,int mins=INT_MIN,int maxs=INT_MAX) 
    {
        // Your code here
        if(root==NULL) return true;
        if(root->data<=mins || root->data>=maxs) return false;
        bool ans=true;
        ans= ans && isBST(root->left,mins,root->data);
        ans = ans && isBST(root->right,root->data,maxs);
        return ans;
    }
};