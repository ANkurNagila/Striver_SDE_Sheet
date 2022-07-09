/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL)
        return NULL;
    
    TreeNode<int> *head=new TreeNode<int>(root->data);
    TreeNode<int> *ele1=flattenBinaryTree(root->left);
    TreeNode<int> *ele2=flattenBinaryTree(root->right);
    
    if(ele1!=NULL){
        head->right=ele1;
        while(ele1->right!=NULL)
            ele1=ele1->right;
    }
    else{
        ele1=head;
    }
    
    if(ele2!=NULL){
        ele1->right=ele2;
    }
    
    return head;
}
