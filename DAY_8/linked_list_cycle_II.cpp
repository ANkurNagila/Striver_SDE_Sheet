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

Node *firstNode(Node *head)
{
    if(head==NULL || head->next==NULL)
        return NULL;
    
    Node *fast=head->next->next;
    Node *slow=head->next;
    
    int flag=0;
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            flag=1;
            break;
        }
    }
    
    if(flag==0)
        return NULL;
    
    int i=0;
    Node *temp=head;
    while(temp!=slow){
        if(temp==slow)
            return temp;
        temp=temp->next;
        slow=slow->next;
    }
    return temp;    
}
