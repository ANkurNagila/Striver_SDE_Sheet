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
int height(BinaryTreeNode<int> *root){
    if(root==NULL)
        return 0;
    
    return max(height(root->left),height(root->right))+1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root==NULL)
        return true;
    
    int ele1=height(root->left);
    int ele2=height(root->right);
    
    return (abs(ele1-ele2)<=1)&&(isBalancedBT(root->left))&&(isBalancedBT(root->right));
}
