class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        else if(list1 ==NULL) return list2;
        else if(list2==NULL) return list1;
         
        ListNode* head=NULL;
        ListNode* curr=NULL;
        if(list1->val<list2->val){
            head=list1;
            list1=list1->next;
        }
        else if(list1->val>=list2->val){
            head=list2;
            list2=list2->next;
        }
       curr=head;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<list2->val)
            {
                curr->next=list1;
                list1=list1->next;
            }
            else if(list1->val>=list2->val)
            {
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }
        while(list1!=NULL)
        {
            curr->next=list1;
            list1=list1->next;
            curr=curr->next;
        }
        while(list2!=NULL)
        {
            curr->next=list2;
            list2=list2->next;
            curr=curr->next;
        }
        return head;
    }
};