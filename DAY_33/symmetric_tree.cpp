/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool help(BinaryTreeNode<int> *root1,BinaryTreeNode<int> *root2){
    if(root1==NULL && root2==NULL)
        return true;
    else if((root1==NULL && root2!=NULL)||(root2==NULL && root1!=NULL))
        return false;
    
    if(root1->data!=root2->data)
        return false;
    
    bool ele1=help(root1->left,root2->right);
    bool ele2=help(root1->right,root2->left);
    
    return ele1 && ele2;
    
}


bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return true;
    
    return help(root->left,root->right);
}
