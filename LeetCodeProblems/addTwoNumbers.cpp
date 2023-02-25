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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ansHead=new ListNode((l1->val+l2->val)%10);
        ListNode* ans=ansHead;
        int carry=(l1->val+l2->val)/10;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL && l2!=NULL)
        {
            ListNode* temp= new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            l1=l1->next;
            l2=l2->next;
            ans->next=temp;
            ans=temp;
        }
        while(l1!=NULL)
        {
            ListNode* temp= new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry)/10;
            l1=l1->next;
            ans->next=temp;
            ans=temp; 
        }
        while(l2!=NULL)
        {
            ListNode* temp= new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry)/10;
            l2=l2->next;
            ans->next=temp;
            ans=temp; 
        }
       if (carry>0)
        {
            ListNode* temp= new ListNode(carry);
            ans->next=temp;
            ans=temp; 
        }
        return ansHead;
    }
};