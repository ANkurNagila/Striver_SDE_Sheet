/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre=-1;
    int succ=-1;
    
    BinaryTreeNode<int> *temp=root;
    while(temp!=NULL){
        if(temp->data<=key){
            temp=temp->right;
        }
        else{
            succ=temp->data;
            temp=temp->left;
        }
    }
    
    temp=root;
    while(temp!=NULL){
        if(temp->data>=key){
            temp=temp->left;
        }
        else{
            pre=temp->data;
            temp=temp->right;
        }
    }
    
    return {pre,succ};
}
