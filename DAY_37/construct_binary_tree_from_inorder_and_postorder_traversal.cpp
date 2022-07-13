/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int> *help(vector<int> &inOrder,vector<int> &postOrder,int start_i,int end_i,int start_p,int end_p){
    if(start_i>end_i || start_p>end_p)
        return NULL;
    
    TreeNode<int> *root=new TreeNode<int>(postOrder[end_p]);
    int x;
    for(int i=start_i;i<=end_i;i++){
        if(inOrder[i]==postOrder[end_p]){
            x=i;
            break;
        }
    }
    
    int size=x-start_i-1;
    TreeNode<int> *l=help(inOrder,postOrder, start_i, x-1, start_p, start_p+size);
    TreeNode<int> *r=help(inOrder,postOrder, x+1, end_i ,start_p+size+1 ,end_p-1);
    
    root->left=l;
    root->right=r;
    
    return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	TreeNode<int> *root=help(inOrder,postOrder,0,inOrder.size()-1,0,postOrder.size()-1);
    return root;
}
