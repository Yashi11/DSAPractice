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
    void findNums(TreeNode* root,vector<int>& nums,int curr=0)
    {
        if(root==NULL){
            cout<<curr;
            nums.push_back(curr);
            return;
        }
        curr=curr*10+root->val;
        if(!root->left && !root->right){
            nums.push_back(curr);
            return;
        }
        if(root->left) findNums(root->left,nums,curr);
        if(root->right) findNums(root->right,nums,curr);
    }
    int sumNumbers(TreeNode* root) {
      vector<int> nums;
      findNums(root,nums);
      int ans=0;
      for(int i=0;i<nums.size();i++)
      {
          ans+=nums[i];
      } 
      return ans;
    }
};