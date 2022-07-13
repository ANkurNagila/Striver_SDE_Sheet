/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<stack>
void push_all(TreeNode<int> *root,stack<TreeNode<int>*> &x){
    for(;root!=NULL;x.push(root),root=root->right);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    if(root==NULL)
        return -1;
    int count=0;
    stack<TreeNode<int> *> x;
    push_all(root,x);
    
    while(x.size()!=0){
        TreeNode<int> *t=x.top();
        x.pop();
        count++;
        if(count==k)
            return t->data;
        
        if(t->left!=NULL)
            push_all(t->left,x);
        
    }
    
    return -1;
    
}
