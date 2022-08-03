#include<bits/stdc++.h>
vector<int> dij_algo(vector<pair<int,int>> graph[],int n,int source){
    vector<int> distance(n,INT_MAX);
    priority_queue< pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> x;
    x.push({0,source});
    distance[source]=0;
    
    while(x.size()!=0){
        pair<int,int> temp=x.top();
        int node=temp.second;
        x.pop();
        
        for(auto it: graph[node]){
            
            int dis=distance[node]+it.second;
            if(distance[it.first]>dis){
                distance[it.first]=dis;
                x.push({distance[it.first],it.first});
            }
        }
        
    }
    
    return distance;
}


vector<int> dijkstra(vector<vector<int>> &g, int n, int m, int source) {
    vector<pair<int,int>> graph[n];
    
    for(int i=0;i<m;i++){
        graph[g[i][0]].push_back({g[i][1],g[i][2]});
        graph[g[i][1]].push_back({g[i][0],g[i][2]});
    }
    
    vector<int> ans=dij_algo(graph,n,source);
    return ans;
}
