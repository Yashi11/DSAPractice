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
    ListNode* reverseL(ListNode* l)
    {
        ListNode* curr=l;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseL(l1);
        l2=reverseL(l2);
        ListNode* ansH=l1;
        int carry=0;
        ListNode* tail;
        while(l1!=NULL && l2!=NULL)
        {
            int n=(l1->val)+(l2->val)+carry;
            l1->val=(n%10);
            carry=n/10;
            tail=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int n=(l1->val)+carry;
            ListNode* tmp=new ListNode(n%10);
            tail->next=tmp;
            carry=n/10;
            tail=tail->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int n=(l2->val)+carry;
            ListNode* tmp=new ListNode(n%10);
            tail->next=tmp;
            carry=n/10;
            tail=tail->next;
            l2=l2->next;
        }
        while(carry>0)
        {
            ListNode* tmp=new ListNode(carry%10);
            tail->next=tmp;
            tail=tail->next;
            carry=carry/10;
        }
        l1=ansH;
        return reverseL(ansH);
    }
};