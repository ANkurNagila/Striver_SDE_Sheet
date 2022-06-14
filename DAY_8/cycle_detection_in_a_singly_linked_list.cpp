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

bool detectCycle(Node *head)
{
    if(head==NULL || head->next==NULL)
        return false;
    
    Node *fast=head->next->next;    
    Node *slow=head->next;
    
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        if(fast==slow)
            return true;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return false;
}
