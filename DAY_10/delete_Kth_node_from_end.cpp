#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    // Write your code here.
    if(head==NULL ||k==0)
        return head;
    
    int n=1;
    LinkedListNode<int> *temp=head;
    
    while(temp->next!=NULL){
        n++;
        temp=temp->next;
    }
    
    k=n-k-1;
    temp=head;
    if(k==-1)
        head=head->next;
    else{
        while(k--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
    
    return head;
}
