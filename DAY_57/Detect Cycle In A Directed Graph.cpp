bool isCycleDFS(int node, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
    
    visited[node]=true;
    dfsVisited[node]=true;
    
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            if(isCycleDFS(neighbour, adj, visited, dfsVisited)){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, vector<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(isCycleDFS(i, adj, visited, dfsVisited)){
                return true;
            }
        }
    }
    return false;
    
}
