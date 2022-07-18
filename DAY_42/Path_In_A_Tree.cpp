/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
bool help(TreeNode<int> *root,int x,vector<int> &ans){
    if(root==NULL)
        return false;
    
    bool short_ans_left=help(root->left,x,ans);
    bool short_ans_right=help(root->right,x,ans);
    
    if(short_ans_left ||short_ans_right||root->data==x){
        ans.push_back(root->data);
        return true;
    }
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    bool ele=help(root,x,ans);
    int n=ans.size();
    for(int i=0,j=n-1;i<j;i++,j--)
        swap(ans[i],ans[j]);
    return ans;
}
