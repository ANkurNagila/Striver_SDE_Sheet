/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int> *help(vector<int> &preOrder,int &i,int bound){
    if(preOrder.size()<=i||bound<preOrder[i])
        return NULL;
    
    TreeNode<int> *root=new TreeNode<int>(preOrder[i++]);
    TreeNode<int> *l=help(preOrder,i,root->data);
    TreeNode<int> *r=help(preOrder,i,bound);
    
    root->left=l;
    root->right=r;
    return root;
    
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i=0;
    TreeNode<int> *root=help(preOrder,i,INT_MAX);
    return root;
}
