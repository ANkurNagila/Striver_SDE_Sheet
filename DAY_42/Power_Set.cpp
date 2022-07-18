void help(vector<int> &v,int n,vector<vector<int>> &ans){
    if(n==0)
        return ;
    
    help(v,n-1,ans);
    int size=ans.size();
    for(int i=0;i<size;i++){
        if(i==0)
            ans.push_back({v[n-1]});
        else{
            vector<int> temp=ans[i];
            if(temp.back()<=v[n-1]){
                temp.push_back(v[n-1]);
                ans.push_back(temp);
            }
        }
    }
    
}

vector<vector<int>> pwset(vector<int>v)
{
    int n=v.size();
    vector<vector<int>> ans;
    ans.push_back({});
    help(v,n,ans);
    return ans;
}
