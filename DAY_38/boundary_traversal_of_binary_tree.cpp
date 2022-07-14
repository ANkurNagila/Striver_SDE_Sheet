/************************************************************

    Following is the Binary Tree node structure:
    
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
#include<bits/stdc++.h>
vector<int> right_view(TreeNode<int> *root){
    if(root==NULL)
        return {};
    
    stack<int> t;
    queue<TreeNode<int> *> x;
    x.push(root);
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            if(x.front()->right!=NULL)
                x.push(x.front()->right);
            else if(x.front()->left!=NULL)
                x.push(x.front()->left);
            else if(x.front()->left==NULL && x.front()->right==NULL){
                x.pop();
                continue;
            } 
            t.push(x.front()->data);
            x.pop();
        }
    }
    
    vector<int> ans;
    while(t.size()!=0){
        ans.push_back(t.top());
        t.pop();
    }
    
    return ans;    
}

void bottom_view(TreeNode<int> *root,vector<int> &ans){
    if(root==NULL)
        return ;
    
    bottom_view(root->left,ans);
    if(root->left==NULL && root->right==NULL)
        ans.push_back(root->data);
    bottom_view(root->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    if(root==NULL)
        return {};
    
    vector<int> ans;
    if(root->left==NULL && root->right==NULL)
        return {root->data};
    else
        ans.push_back(root->data);
    
    queue<TreeNode<int> *> x;
    if(root->left!=NULL)
        x.push(root->left);
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            if(x.front()->left!=NULL)
                x.push(x.front()->left);
            else if(x.front()->right!=NULL)
                x.push(x.front()->right);
            else if(x.front()->left==NULL && x.front()->right==NULL){
                x.pop();
                continue;
            } 
            ans.push_back(x.front()->data);
            x.pop();
        }
    }
    
    bottom_view(root,ans);
    vector<int> r=right_view(root->right);
    
    for(auto it:r)
        ans.push_back(it);
    
    return ans;
}
