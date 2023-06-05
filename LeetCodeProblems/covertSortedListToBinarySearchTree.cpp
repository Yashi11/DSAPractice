/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) {return NULL;}
        else if(head->next==NULL){
            TreeNode* ans=new TreeNode(head->val);
            return ans;
        }
        ListNode* fast=head;
        ListNode*slow=head;
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=NULL && fast->next!=NULL);
        ListNode* prev=head;
        while(prev->next!=slow)
        {
            prev=prev->next;
        }
        TreeNode* ans=new TreeNode(slow->val);
        prev->next=NULL;
        ans->left=sortedListToBST(head);
        ans->right=sortedListToBST(slow->next);
        return ans;
    }
};