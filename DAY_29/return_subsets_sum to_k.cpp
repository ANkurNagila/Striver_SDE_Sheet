void helper(int i,int target,vector<int> &arr,vector<int> &x,vector<vector<int>> &y){
        if(target==0)
                y.push_back(x);
            
        if(i==arr.size())
            return ;
        
        for(;i<arr.size();i++){
            x.push_back(arr[i]);
            helper(i+1,target-arr[i],arr,x,y);
            x.pop_back();
        }
    }

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> x;
    vector<vector<int>> y;
    helper(0,k,arr,x,y);
    
    return y;
}
