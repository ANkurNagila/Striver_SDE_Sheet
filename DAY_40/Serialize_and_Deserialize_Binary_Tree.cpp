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
#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
    if(root==NULL)
        return "#";
    
    string s="";
    queue<TreeNode<int> *> x;
    x.push(root);
    s+=to_string(root->data);
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            TreeNode<int> *temp=x.front();
            if(temp->left!=NULL){
                s=s+","+to_string(temp->left->data);
                x.push(temp->left);
            }
            else
                s+=",#";
            
            if(temp->right!=NULL){
                s=s+","+to_string(temp->right->data);
                x.push(temp->right);
            }
            else
                s+=",#";
            
            x.pop();
        }
    }
    
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.size()==1)
        return NULL;
    
    string str;
    stringstream s(serialized);
    getline (s, str, ',');
    TreeNode<int> *root=new TreeNode<int>(stoi(str));
    queue<TreeNode<int> *> x;
    x.push(root);
    
    while(x.size()!=0){
        getline (s, str, ',');
        if(str!="#"){
            TreeNode<int> *l=new TreeNode<int>(stoi(str));
            x.front()->left=l;
            x.push(l);
        }
        else{
            x.front()->left=NULL;
        }
        getline (s, str, ',');
        if(str!="#"){
            TreeNode<int> *r=new TreeNode<int>(stoi(str));
            x.front()->right=r;
            x.push(r);
        }
        else{
            x.front()->right=NULL;
        }
        x.pop();
    }
    
    return root;

}



