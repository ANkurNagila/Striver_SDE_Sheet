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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head==NULL || head->next==NULL)
        return head;
    
    LinkedListNode<int> *temp=head->next;
    LinkedListNode<int> *prev=head;  
    prev->next=NULL;
    
    while(temp!=NULL && temp->next!=NULL){
        LinkedListNode<int> *an=temp->next;
        temp->next=prev;
        prev=temp;
        temp=an;
    }
    temp->next=prev;
    prev=temp;
    
    return temp;
}
