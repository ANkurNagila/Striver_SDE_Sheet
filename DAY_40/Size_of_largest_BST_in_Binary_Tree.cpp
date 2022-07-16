/************************************************************

    Following is the Binary Tree node structure
    
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
class Node{
    public:
        int max_size,maxi,mini;
    
    Node(int max_size,int maxi,int mini){
        this->max_size=max_size;
        this->maxi=maxi;
        this->mini=mini;
    }
};

Node help(TreeNode<int> *root){
    if(root==NULL)
        return Node(0,INT_MIN,INT_MAX);
    
    Node l=help(root->left);
    Node r=help(root->right);
    
    if(l.maxi<root->data && r.mini>root->data){
        return Node((l.max_size+r.max_size+1),max(r.maxi,root->data),min(root->data,l.mini));
    }
    
    int i=max(l.max_size,r.max_size);
    return Node(i,INT_MAX,INT_MIN);
}


int largestBST(TreeNode<int>* root) 
{
    return help(root).max_size;
}
