vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    ans.push_back(0);
    int n=num.size();
    
    if(n==0)
        return ans;
    
    for(int i=0;i<n;i++){
        int size=ans.size();
        for(int j=0;j<size;j++){
            ans.push_back(num[i]+ans[j]);
        }
    }
    
    sort(ans.begin(),ans.end());
    
    return ans;
    
}
