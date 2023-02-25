/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* evenH=NULL;
        Node* oddH=NULL;
        Node* evenT=evenH;
        Node* oddT=oddH;
        while(head!=NULL)
        {
            if(head->data%2==0)
            {
                if(evenH==NULL)
                {
                    evenH=head;
                    evenT=evenH;
                }
                else{
                    evenT->next=head;
                    evenT=head;
                }
            }
            if(head->data%2==1)
            {
                if(oddH==NULL)
                {
                    oddH=head;
                    oddT=oddH;
                }
                else{
                    oddT->next=head;
                    oddT=head;
                }
            }
            head=head->next;
        }
        if(oddT!=NULL){
            oddT->next=NULL;
        }
        if(evenH!=NULL)
        {
            evenT->next=oddH;
        }
        else{
            evenH=oddH;
        }
        return evenH;
    }
};