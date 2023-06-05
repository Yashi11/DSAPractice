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
class BSTIterator {
public:
    vector<int> inOrder;
    int indx;
    BSTIterator(TreeNode* root) {
        inorder(root,inOrder);
        indx=0;
    }
    void inorder(TreeNode* root,vector<int>& inOrder){
        if(root==NULL) return;
        inorder(root->left,inOrder);
        inOrder.push_back(root->val);
        inorder(root->right,inOrder);  
    }
    int next() {
        if(indx>=inOrder.size()) return -1;
        return inOrder[indx++];
    }
    
    bool hasNext() {
        if(indx<inOrder.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */