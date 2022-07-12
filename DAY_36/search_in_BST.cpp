/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL)
        return false;
    
    bool short_ans=false;
    if(root->data==x)
        return true;
    else if(root->data>x)
        short_ans=searchInBST(root->left,x);
    else
        short_ans=searchInBST(root->right,x);
    
    return short_ans;
}
