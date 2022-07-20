/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int x)
{
    if(root==NULL)
        return -1;
    int ans=-1;
    
    if(root->val<=x){
        ans=root->val;
        int r=floorInBST(root->right,x);
        return max(r,ans);
    }
    else{
        int l=floorInBST(root->left,x);
        return l;  
    }
}
