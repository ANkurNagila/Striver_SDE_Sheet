#include<bits/stdc++.h>

bool compare(vector<int> &v1,vector<int> &v2){
    return v1[2]<v2[2];
}

int findparent(int i,vector<int> &parent){
    if(parent[i]==i)
        return i;
    
    return findparent(parent[i],parent);
}

int kruskalMST(int v, int E, vector<vector<int>> &graph) {
    sort(graph.begin(),graph.end(),compare);
    
    vector<int> parent(v+1);
    for(int i=0;i<v+1;i++){
        parent[i]=i;
    }
    
    int count=0,i=0;
    int ans=0;
    while(count<v-1 && i<E){
        vector<int> curr=graph[i];
        int sourceparent=findparent(graph[i][0],parent);
        int destparent=findparent(graph[i][1],parent);
        
        if(sourceparent!=destparent){
            ans+=graph[i][2];
            count++;
            parent[sourceparent]=destparent;
        }
        i++;
    }
    return ans;
}
