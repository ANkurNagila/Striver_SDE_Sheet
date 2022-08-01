#include<bits/stdc++.h>
void help(vector<vector<int>> &graph,int n,int start,vector<int> &visited,vector<int> &ans){
    
    queue<int> x;
    x.push(start);
    visited[start]=1;
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            cout<<x.front()<<" ";
            
            for(int i=0;i<n;i++){
                if(i==x.front())
                    continue;
                if(graph[x.front()][i]==1 && visited[i]!=1){
                    x.push(i);
                    visited[i]=1;
                }
            }
            
            x.pop();
        }
    }
}


void BFS_help(vector<vector<int>> &graph,int n,vector<int> &ans){
    vector<int> visited(n,0);
    
    for(int i=0;i<n;i++){
        if(visited[i]!=1)
            help(graph,n,i,visited,ans);
    }
}

vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    int E=edges.size();
    vector<vector<int>> graph(V,vector<int> (V));
    
    for(int i=0;i<E;i++){
        graph[edges[i].first][edges[i].second]=1;
        graph[edges[i].second][edges[i].first]=1;
    }
    
    vector<int> ans;
    BFS_help(graph,V,ans);
    
    return ans;
}
