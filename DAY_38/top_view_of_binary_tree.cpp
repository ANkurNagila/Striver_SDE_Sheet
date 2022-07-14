/************************************************************

    Following is the TreeNode class structure:

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
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root==NULL)
        return {};
    
    map<int,int> x;
    queue<pair<TreeNode<int>*,int>> temp;
    
    temp.push({root,0});
    
    while(temp.size()!=0){
        int size=temp.size();
        while(size--){
            TreeNode<int> *s=temp.front().first;
            int key=temp.front().second;
            if(s->left!=NULL)
                temp.push({s->left,key-1});
            if(s->right!=NULL)
                temp.push({s->right,key+1});
            
            if(not(x.find(key)!=x.end()))
                x[key]=s->val;
            
            temp.pop();
        }
    }
    
    vector<int> ans;
    for(auto it:x){
        ans.push_back(it.second);
    }
    return ans;
}
