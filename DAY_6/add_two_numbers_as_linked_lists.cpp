#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
	        Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    if(head1!=NULL && head2==NULL)
        return head1;
    else if(head1==NULL && head2!=NULL)
        return head2;
    
    int val=head1->data+head2->data;
    int c=val/10;
    Node* head3=new Node(val%10);
    Node* temp=head3;
    head1=head1->next;
    head2=head2->next;
    
    while(head1!=NULL && head2!=NULL){
        val=head1->data+head2->data+c;
        c=val/10;
        Node *temp2=new Node(val%10);
        temp->next=temp2;
        temp=temp->next;
        head1=head1->next;
        head2=head2->next;
    }
    
    while(head2!=NULL){
        val=head2->data+c;
        c=val/10;
        Node *temp2=new Node(val%10);
        temp->next=temp2;
        temp=temp->next;
        head2=head2->next;
    }
    
    while(head1!=NULL){
        val=head1->data+c;
        c=val/10;
        Node *temp2=new Node(val%10);
        temp->next=temp2;
        temp=temp->next;
        head1=head1->next;
    }
    
    if(c!=0)
    {
        Node *temp2=new Node(c);
        temp->next=temp2;
        temp=temp->next;
    }
    return head3;
}
