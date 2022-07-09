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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    queue<TreeNode<int>*> temp;
    if(root!=NULL)
        temp.push(root);
    vector<int> ans;
    
    while(temp.size()!=0){
        int size=temp.size();
        ans.push_back(temp.front()->data);
        
        while(size--){
            if(temp.front()->left!=NULL)
                temp.push(temp.front()->left);
            if(temp.front()->right!=NULL)
                temp.push(temp.front()->right);
            
            temp.pop();
        }
    }
    
    return ans;
    
    
    
    
}
