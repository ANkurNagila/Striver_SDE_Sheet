/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<stack>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> x;
    int i=0;
    
    vector<int> ans;
    
    if(root!=NULL)
        x.push(root);
    
    while(x.size()!=0){
        int size=x.size();
        stack<BinaryTreeNode<int> *> y;
        while(size--){
            if(i%2==0){
                if(x.top()->left!=NULL)
                    y.push(x.top()->left);
                if(x.top()->right!=NULL)
                    y.push(x.top()->right);
            }
            else{
                if(x.top()->right!=NULL)
                    y.push(x.top()->right);
                if(x.top()->left!=NULL)
                    y.push(x.top()->left);
            }
            ans.push_back(x.top()->data);
            x.pop();
        }
        i++;
        x=y;
    }
    
    return ans;
    
    
}
