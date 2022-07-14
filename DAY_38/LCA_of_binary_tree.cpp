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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(root==NULL)
        return -1;
    
    if(root->data==x)
        return x;
    else if(root->data==y)
        return y;
    
    int l=lowestCommonAncestor(root->left,x,y);
    int r=lowestCommonAncestor(root->right,x,y);
    
    if(l!=-1 && r!=-1)
        return root->data;
    else if(l==-1 && r!=-1)
        return r;
    else if(l!=-1 && r==-1)
        return l;
    
    return -1;
    
}
