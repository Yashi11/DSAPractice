class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        // code here
        Node* prev=NULL;
        Node* curr=head;
        Node* next;
        
        while(k--)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        Node* tail=head;
        head=prev;
        prev=NULL;

        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        tail->next=prev;
        return head;
    }
};