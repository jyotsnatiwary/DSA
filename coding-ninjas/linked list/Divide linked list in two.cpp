/*Divide linked list in two
Send Feedback
Write a function that takes one list and divides up its nodes to create two smaller lists A and B. The sub lists should be made from alternating elements in the original list.
Nodes should be in the reverse order of which they occurred in the source list.
Print both linked lists in different lines.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output format :
Line 1 : Output Linked List 1 elements (separated by space)
Line 2 : Output Linked List 2 elements (separated by space)
Constraints :
1 <= n <= 10^4
Sample Input :
 8 2 5 9 1 4 3 7 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 8.
Sample Output :
 3 1 5 8
 7 4 9 2*/
 
 
typedef Node<int> node;

void reverse(node* head){
    if(head==NULL) return ;
    node* curr=head;
    node* prev=NULL;
    node* next=NULL;
    
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    curr=prev;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
void AlternatingSplit(Node<int>* head) {
    if(head==NULL) return;
    node* head1=NULL;node* tail1=NULL;
    node* head2=NULL;node* tail2=NULL;
    int count=0;    
    node* curr=head;
    while(curr!=NULL){
        if(count%2==0){
            if(head1==NULL){
                head1=curr;
                tail1=curr;
            }else{
                tail1->next=curr;
                tail1=curr;
            }            
        }else{
            if(head2==NULL){
                head2=curr;
                tail2=curr;
            }else{
                tail2->next=curr;
                tail2=curr;
            }
        }
        curr=curr->next;
        count++;        
    }
    tail1->next=NULL;
    tail2->next=NULL;
    if(head1!=NULL) reverse(head1);
    if(head2!=NULL) reverse(head2);    
}
