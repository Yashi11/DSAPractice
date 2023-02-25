
//Naive O(N^2) Solution
/*
The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
// class Solution
// {
//     public:
//     Node *compute(Node *head)
//     {
//         // your code goes here
//         bool flag=false;
//         Node* temp=head;
//         Node* prev=NULL;
//         while(temp->next && temp)
//         {
//             if(temp->next->data > temp->data)
//             {
//                 flag=true;
//                 if(temp==head)
//                 {
//                     head=temp->next;
//                 }
//                 else{
//                     prev->next=temp->next;
//                 }
//             }
//             prev=temp;
//             temp=temp->next;
//         }
//         if(flag) return compute(head);
//         else return head;
        
//     }
    
// };
   
// Optimal O(N) Solution
class Solution
{
    public:
    Node* reverseList(Node* head)
    {
       Node* temp=head;
        Node* prev=NULL;
        Node* next;
        while(temp)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        //REVERSE THE LIST
        head=reverseList(head);
        int maxTillNow=INT_MIN;
        Node* temp=head;
        Node* prev=NULL;
        while(temp)
        {
            maxTillNow=max(maxTillNow,temp->data);
            if(temp->data<maxTillNow)
            {
               if(temp==head){
                   temp=temp->next;
                   head=temp;
                   continue;
               } 
               prev->next=temp->next;
               temp=temp->next;
               continue;
            }
            prev=temp;
            temp=temp->next;
        }
        return reverseList(head);
        
    }
    
};