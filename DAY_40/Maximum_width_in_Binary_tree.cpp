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

int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL)
        return 0;
    
    int maxi=0;
    queue<TreeNode<int> *> x;
    x.push(root);
    maxi=1;
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            if(x.front()->left!=NULL)
                x.push(x.front()->left);
            if(x.front()->right!=NULL)
                x.push(x.front()->right);
            x.pop();
        }
        if(maxi<x.size())
            maxi=x.size();
    }
    
    return maxi;
}
