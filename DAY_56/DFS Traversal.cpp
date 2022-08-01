void help(vector<vector<int>> &graph,int n,int start,vector<int> &visited,vector<int> &temp){
    if(start==n)
        return ;
    
    visited[start]=1;
    temp.push_back(start);
    for(int i=0;i<n;i++){
        if(start==i)
            continue;
        if(graph[start][i]==0||visited[i]==1)
            continue;
        help(graph,n,i,visited,temp);
    }
}

void DFS(vector<vector<int>> &graph,int n,vector<vector<int>> &ans){
    vector<int> visited(n,0);
    vector<int> temp;
    
    for(int i=0;i<n;i++){
        if(visited[i]!=1)
            help(graph,n,i,visited,temp);
        if(temp.size()>0){
            ans.push_back(temp);
            temp.clear();
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(V,vector<int> (V));
    
    for(int i=0;i<E;i++){
        graph[edges[i][0]][edges[i][1]]=1;
        graph[edges[i][1]][edges[i][0]]=1;
    }
    
    
    vector<vector<int>> ans;
    DFS(graph,V,ans);
    
    return ans;
}
