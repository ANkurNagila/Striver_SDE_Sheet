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
TreeNode<int> *help(vector<int> &inorder, vector<int> &preorder,int in_i,int in_j,int pre_i,int pre_j){
    
    if(in_i>in_j || pre_i>pre_j)
        return NULL;
    
    TreeNode<int> *root=new TreeNode<int>(preorder[pre_i]);
    int x;
    for(int i=in_i;i<=in_j;i++){
        if(inorder[i]==preorder[pre_i]){
            x=i;
            break;
        }
    }
    
    int size=x-in_i+1;
    TreeNode<int> *l=help(inorder,preorder,in_i,x-1,pre_i+1,pre_i+size-1);
    TreeNode<int> *r=help(inorder,preorder,x+1,in_j,pre_i+size,pre_j);
    
    root->left=l;
    root->right=r;
    
    return root;
    
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    TreeNode<int> *root=help(inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);
    return root;
}
