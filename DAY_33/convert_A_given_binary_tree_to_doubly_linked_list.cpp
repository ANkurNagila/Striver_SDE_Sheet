/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
        return NULL;
    
    BinaryTreeNode<int> *head=new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *ele1=BTtoDLL(root->left);
    BinaryTreeNode<int> *head1=ele1;
    BinaryTreeNode<int> *ele2=BTtoDLL(root->right);
    
    if(ele1!=NULL){
        while(ele1->right!=NULL)
            ele1=ele1->right;
        
        ele1->right=head;
        head->left=ele1;
        ele1=head;
    }
    else{
        head1=head;
        ele1=head;
    }
    
    if(ele2!=NULL){
        ele1->right=ele2;
        ele2->left=ele1;
    }
    
    return head1;
}
