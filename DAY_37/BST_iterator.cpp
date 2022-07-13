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
#include<stack>
class BSTiterator
{
    private:
        stack<TreeNode<int> *> x;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        TreeNode<int> *temp=root;
        while(temp!=NULL){
            this->x.push(temp);
            temp=temp->left;
        }
    }

    int next()
    {
        // write your code here
        TreeNode<int> *t=this->x.top();
        this->x.pop();
        if(t->right!=NULL){
            this->x.push(t->right);
            TreeNode<int> *temp2=x.top()->left;
            while(temp2!=NULL){
                this->x.push(temp2);
                temp2=temp2->left;
            }
        }
        
        return t->data;
    }

    bool hasNext()
    {
        return this->x.size()>0;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
