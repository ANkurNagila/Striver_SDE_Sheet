/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int help(TreeNode<int> *root,int *maxi){
    if(root==NULL)
        return 0;
    
    int l=help(root->left,maxi);
    int r=help(root->right,maxi);
    
    *maxi=max(*maxi,l+r);
    return max(l,r)+1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    if(root==NULL)
        return 0;
    
    int maxi=0;
    int ele=help(root,&maxi);
    return maxi;
}
