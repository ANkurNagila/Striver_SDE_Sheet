string cycleDetection (vector<vector<int>>& edges, int V, int E)
{
    vector<int> union_find(V);
    for(int i=0;i<V;i++)
        union_find[i]=i;
    
    for(int i=0;i<E;i++){
        //cout<<union_find[edges[i][0]-1]<<" "<<union_find[edges[i][1]-1]<<endl;
        if(union_find[edges[i][0]-1]!=union_find[edges[i][1]-1]){
            int mini=min(union_find[edges[i][0]-1],union_find[edges[i][1]-1]);
            for(int j=0;j<V;j++){
                if(j==edges[i][0]-1 || j==edges[i][1]-1)
                    continue;
                if(union_find[j]==union_find[edges[i][0]-1]||union_find[j]==union_find[edges[i][1]-1])
                    union_find[j]=mini;
            }
            union_find[edges[i][0]-1]=mini;
            union_find[edges[i][1]-1]=mini;
        }
        else
            return "Yes";
    }
    
    return "No";
}
