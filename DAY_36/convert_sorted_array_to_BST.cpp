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
TreeNode<int> *help(vector<int> &arr,int i,int j){
    if(i>j)
        return NULL;
    
    int mid=(i+j)/2;
    TreeNode<int> *head=new TreeNode<int>(arr[mid]);
    head->left=help(arr,i,mid-1);
    head->right=help(arr,mid+1,j);
    
    return head;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    if(n==0)
        return NULL;
    
    TreeNode<int> *head=help(arr,0,n-1);
    return head;
}
