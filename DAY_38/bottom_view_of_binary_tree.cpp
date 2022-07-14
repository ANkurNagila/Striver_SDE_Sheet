/*************************************************************
 
    Following is the Binary Tree node structure.

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
#include<bits/stdc++.h>
vector<int> bottomView(BinaryTreeNode<int> * root){
    if(root==NULL)
        return {};
    
    map<int,int> x;
    queue<pair<BinaryTreeNode<int>*,int>> temp;
    
    temp.push({root,0});
    
    while(temp.size()!=0){
        int size=temp.size();
        while(size--){
            BinaryTreeNode<int> *s=temp.front().first;
            int key=temp.front().second;
            if(s->left!=NULL)
                temp.push({s->left,key-1});
            if(s->right!=NULL)
                temp.push({s->right,key+1});
            
            x[key]=s->data;
            
            temp.pop();
        }
    }
    
    vector<int> ans;
    for(auto it:x){
        ans.push_back(it.second);
    }
    return ans;
}
