Node *findMiddle(Node *head) {
    if(head==NULL||head->next==NULL)
        return head;
    
    Node *slow=head->next;
    Node *fast=head->next->next;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
