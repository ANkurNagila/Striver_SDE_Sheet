vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<vector<int>> temp;
    
    vector<int> a,b;
    temp.push_back(a);
    b.push_back(0);
    
    for(int i=0;i<n;i++){
        int x=temp.size();
        for(int j=0;j<x;j++){
            vector<int> f=temp[j];
            f.push_back(arr[i]);
            b.push_back(b[j]+arr[i]);
            if((b[j]+arr[i])==k)
                ans.push_back(f);
            temp.push_back(f);
        }
    }
    
    return ans;    
}
