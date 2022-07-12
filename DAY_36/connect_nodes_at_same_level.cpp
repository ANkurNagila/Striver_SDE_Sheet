/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<queue>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode<int> *> x;
    x.push(root);
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            if(x.front()->left!=NULL){
                x.push(x.front()->left);
            }
            if(x.front()->right!=NULL){
                x.push(x.front()->right);
            }
            
            BinaryTreeNode<int> *temp=x.front();
            x.pop();
            
            if(size>0)
                temp->next=x.front();
        }
    }
    
}
