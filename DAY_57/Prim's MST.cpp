#include<bits/stdc++.h>
int Cal_min(vector<int> &weight,vector<bool> &visited,int n){
    int min_vertex=-1;
    
    for(int i=1;i<n;i++){
        if(!visited[i] && (min_vertex==-1 || weight[i]<weight[min_vertex]))
            min_vertex=i;
    }
    return min_vertex;
}

void prims_algo(vector<vector<int>> &graph,int n,int m,vector<pair<pair<int, int>, int>> &ans){
    
    vector<int> parent(n),weight(n,INT_MAX);
    vector<bool> visited(n,false);
    parent[1]=-1;
    weight[1]=0;
    
    for(int i=1;i<n;i++){
        int min_vertex=Cal_min(weight,visited,n);
        visited[min_vertex]=true;
        
        for(int j=1;j<n;j++){
            if(graph[min_vertex][j]!=0 && !visited[j]){
                if(graph[min_vertex][j]<weight[j]){
                    weight[j]=graph[min_vertex][j];
                    parent[j]=min_vertex;
                }
            }
        }
    }
    
   /* for(int i=0;i<n;i++){
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<" "<<visited[i]<<endl;
    }
    cout<<endl<<endl;
    */
    
    for(int i=2;i<n;i++){
        pair<int,int> ele;
        if(i<parent[i])
            ele={i,parent[i]};
        else
            ele={parent[i],i};
        
        ans.push_back({ele,weight[i]});
    }
    
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    n=n+1;
    vector<vector<int>> graph(n,vector<int> (n));
    
    for(int i=0;i<m;i++){
        graph[g[i].first.first][g[i].first.second]=g[i].second;
        graph[g[i].first.second][g[i].first.first]=g[i].second;
    }
    
    vector<pair<pair<int, int>, int>> ans;
    prims_algo(graph,n,m,ans);
    
    return ans;
    
}
