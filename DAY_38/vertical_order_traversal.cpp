/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int,vector<int>> a;
    queue<pair<TreeNode<int> *,int>> x;
    
    if(root!=NULL)
        x.push({root,0});
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            TreeNode<int> *f=x.front().first;
            int key=x.front().second;
            
            if(f->left!=NULL)
                x.push({f->left,key-1});
            if(f->right!=NULL)
                x.push({f->right,key+1});
            
            if(a.find(key)!=a.end()){
                a[key].push_back(f->data);
            }
            else{
                vector<int> temp;
                temp.push_back(f->data);
                a[key]=temp;
            }
            x.pop();
        }
    }
    
    vector<int> ans;
    for(auto it:a){
        for(auto i:it.second)
            ans.push_back(i);
    }
    return ans;
}
