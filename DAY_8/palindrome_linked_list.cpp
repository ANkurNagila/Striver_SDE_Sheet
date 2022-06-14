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
bool compare(LinkedListNode<int> *head1,LinkedListNode<int> *head2){
    
    while(head1!=NULL){
        if(head1->data!=head2->data)
            return false;
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL)
        return true;
    
    LinkedListNode<int> *temp=head;
    LinkedListNode<int> *head2=new LinkedListNode<int>(temp->data);
    temp=temp->next;
    
    while(temp!=NULL){
        LinkedListNode<int> *temp2=new LinkedListNode<int>(temp->data);
        temp2->next=head2;
        head2=temp2;
        temp=temp->next;
    }
    
    return compare(head,head2);

}
