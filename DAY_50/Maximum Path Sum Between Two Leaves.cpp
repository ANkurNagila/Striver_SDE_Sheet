/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long help(TreeNode<int> *root,long long int *ans){
    if(root==NULL)
        return 0;
    
    long long int l=help(root->left,ans);
    long long int r=help(root->right,ans);
    
    *ans=max(*ans,l+r+root->val);
    int ele=max(l,r);
    
    if(ele<0)
        return root->val;
    return root->val+max(l,r);
    
}


long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==NULL||root->left==NULL||root->right==NULL)
        return -1;
    
    long long int ans=-1;
    help(root,&ans);
    return ans;
}
