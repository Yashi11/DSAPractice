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
    ListNode* reverseFromHere(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        // BASE CONDITITON CHECK
        if(head==NULL || head->next==NULL) return;

        // FINDING MID
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        // REVERSE 2nd HALF
        slow->next=reverseFromHere(fast);
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        ListNode* nextS;
        ListNode* nextF;
        while(fast!=NULL && slow!=NULL){
            nextS=slow->next;
            nextF=fast->next;
            slow->next=fast;
            fast->next=nextS;
            slow=nextS;
            fast=nextF;
        }
    }
};