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
pair<Node *,Node *> reverse(Node *root,Node *tail){
    if(root==tail)
        return {root,tail};
    
    
    tail->next=NULL;
    Node *temp=root;
    Node *after=temp->next;
    Node *prev=NULL;
    while(temp!=NULL){
        after=temp->next;
        temp->next=prev;
        prev=temp;
        temp=after;
    }
    
    return {tail,root};
    
}


Node *getListAfterReverseOperation(Node *head, int n, int arr[]){
    if(n==0||head==NULL||head->next==NULL)
        return head;
    
    int ele=arr[0]-1;
    Node *root=head,*tail=head;
    
    int j=1;
    if(ele<0){
        while(j<n && arr[j]<0){
            j++;
        }
        if(j>=n)
            return head;
        ele=arr[j]-1;
    }
    
    while(ele-- && tail->next!=NULL)
        tail=tail->next;
    
    
    //cout<<root->data<<" "<<tail->data<<endl;
    
    Node *after=tail->next;
    auto x=reverse(root,tail);
    
    head=x.first;
    x.second->next=after;
    root=x.second;
    
    for(int i=j;i<n;i++){
        ele=arr[i]-1;
        if(ele<0)
            continue;
        
        if(root->next==NULL)
            break;
        
        Node *prev=root;
        root=root->next;
        tail=root;
        
        while(ele-- && tail->next!=NULL)
            tail=tail->next;

        after=tail->next;
        x=reverse(root,tail);
        
        prev->next=x.first;
        x.second->next=after;
        root=x.second;
    }
    
    return head;
}
