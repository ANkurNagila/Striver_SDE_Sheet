#include<bits/stdc++.h>
void convertor(unordered_map<int,list<int>>&adj ,vector<vector<int>> &edges ,unordered_map<int,list<int>>& adj_reverse ){
   for(int i = 0 ; i<edges.size(); i++){
       int u = edges[i][0];
       int v = edges[i][1];
       adj[u].push_back(v);
       adj_reverse[v].push_back(u);
   }
}

void topodfs(unordered_map<int,list<int>>&adj , int node , vector<bool>&visited ,stack<int>&st){
   
   visited[node] = true;
   for(auto x : adj[node]){
       if(visited[x] == false ){
        topodfs(adj,x,visited,st);
       }
   }
   st.push(node);
}
void dfs(unordered_map<int,list<int>>& adj_reverse,int node, vector<bool>&visited , vector<int> & temp ){
   
   visited[node] = true;
   temp.push_back(node);
   for(auto x : adj_reverse[node])
   {
       if(visited[x] == false){
           dfs(adj_reverse,x,visited,temp);
       }
   }
   
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
   // Write your code here.
   unordered_map<int,list<int>> adj;
   unordered_map<int,list<int>> adj_reverse; 
   convertor(adj,edges,adj_reverse);
   vector<bool>visited(n,0);
   stack<int>st;
   for(int i = 0 ; i<n ;i++){
       if(visited[i] == false){
           topodfs(adj,i,visited,st);
       }
   }
   vector<vector<int>>ans;
   vector<bool>vis(n,0);
   while(st.empty() == false){
       int node = st.top();
       st.pop();
       if(vis[node] == false){
           vector<int>temp;
           dfs(adj_reverse,node,vis,temp);
           ans.push_back(temp);
       }
   }
   
   return ans;
   
}
