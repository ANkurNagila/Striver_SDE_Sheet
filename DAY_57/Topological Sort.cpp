void help(int start,vector<int> arr[],vector<int> &visited,vector<int> &ans){
    visited[start]=1;
    
    for(auto it:arr[start]){
        if(!visited[it]){
            help(it,arr,visited,ans);
        }
    }
    
    ans.push_back(start);
    //cout<<start<<" ";
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    vector<int> ans;
    vector<int> visited(v);
    vector<int> arr[v];
    
    for(int i=0;i<e;i++){
        arr[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=0;i<v;i++){
        if(!visited[i])
            help(i,arr,visited,ans);
    }
    //cout<<endl;
    return ans;    
}
