/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int> *> x;
        
        if(root!=NULL)
            x.push(root);
        
        vector<int> ans;
        
        while(x.size()!=0){
            int size=x.size();
            while(size--){
                if(x.front()->left!=NULL)
                    x.push(x.front()->left);
                if(x.front()->right!=NULL)
                    x.push(x.front()->right);
                
                ans.push_back(x.front()->val);
                
                x.pop();
            }
        }
        
        return ans;
        
}
