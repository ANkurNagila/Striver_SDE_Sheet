
/*********************************First_Method(hashing used) can be used in binary tree also ********************************
/************************************time is good but not best and space complexity can be very much better*********************************
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<unordered_set>
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    if(root==NULL)
        return false;
    
    unordered_set<int> y;
    queue<BinaryTreeNode<int> *> x;
    x.push(root);
    
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            int ele=k-(x.front()->data);
            if(x.front()->left!=NULL)
                x.push(x.front()->left);
            if(x.front()->right!=NULL)
                x.push(x.front()->right);
            
            if(y.find(ele)!=y.end())
                return true;
            
            y.insert(x.front()->data);
            x.pop();
            
        }
    }
    
    return false;
}
