#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    if(head==NULL || head->next==NULL)
        return head;
    
    int n=1;
    Node *temp=head;
    
    while(temp->next!=NULL){
        n++;
        temp=temp->next;
    }
    
    k=k%n;
    k=n-k;
    temp->next=head;
    while(k--){
        temp=temp->next;
    }
    
    head=temp->next;
    temp->next=NULL;
    return head;
    
    
}
