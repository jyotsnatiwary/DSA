/*Next Number
Send Feedback
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 */

int fnum(Node* head){
    if(head->next==NULL){
        int d=head->data+1;
        head->data=d%10;
        return d/10;
    }
    int ans=fnum(head->next);
    int d1=head->data+ans;
    head->data=d1%10;
    return d1/10;
}

Node* NextLargeNumber(Node *head) {
    int ans=fnum(head);
    if(ans){
        Node* newhead=new Node(1);
        newhead->next=head;
        return newhead;
    }
    return head;
}
