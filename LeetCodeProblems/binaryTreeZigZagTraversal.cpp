// Approach: Linear Traversal with a Twist
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root==NULL) return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(NULL);
//         int lvl=0;
//         vector<int> ans1;
//         while(!q.empty())
//         {
//             if(q.front()==NULL)
//             {
//                 q.pop();
//                 if(lvl%2==0) ans.push_back(ans1);
//                 else{
//                     reverse(ans1.begin(),ans1.end());
//                     ans.push_back(ans1);
//                 }
//                 ans1.clear();
//                 lvl++;
//                 if(q.empty()) continue;
//                 q.push(NULL);
//             }
//            if(q.front()->left) q.push(q.front()->left);
//            if(q.front()->right) q.push(q.front()->right);
//             ans1.push_back(q.front()->val);
//             q.pop();
//         }
//         return ans;
//     }
// };
// Approach: Using 2 stacks
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> currStack;
        stack<TreeNode*> nextStack;
        currStack.push(root);
        while(!currStack.empty() || !nextStack.empty())
        {
            vector<int> ans1;
            while(!currStack.empty())
            {
                ans1.push_back(currStack.top()->val);
                if(currStack.top()->left) nextStack.push(currStack.top()->left);
                if(currStack.top()->right) nextStack.push(currStack.top()->right);
                currStack.pop();
            }
            if(ans1.size()>0) ans.push_back(ans1);
            ans1.clear();
            while(!nextStack.empty())
            {
                ans1.push_back(nextStack.top()->val);
                if(nextStack.top()->right) currStack.push(nextStack.top()->right);
                if(nextStack.top()->left) currStack.push(nextStack.top()->left);
                nextStack.pop();
            }
            if(ans1.size()>0) ans.push_back(ans1);
        }
        return ans;
    }
};