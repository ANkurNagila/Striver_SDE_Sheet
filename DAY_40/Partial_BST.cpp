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

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
        return true;
    
    bool l=validateBST(root->left);
    bool r=validateBST(root->right);
    
    if(l && r){
        if(root->left!=NULL && root->right!=NULL){
            if(root->left->data<=root->data && root->right->data>=root->data)
                return true;
            else
                return false;
        }
        else if(root->left!=NULL && root->right==NULL){
            if(root->left->data<=root->data)
                return true;
            else 
                return false;
        }
        else if(root->right!=NULL && root->left==NULL){
            if(root->right->data>=root->data)
                return true;
            else 
                return false;
        }
        else
            return true;
    }
    
    return false;
        
}
