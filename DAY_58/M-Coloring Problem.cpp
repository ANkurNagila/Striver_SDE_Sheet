bool if_possible(int choice,int start,vector<int> &color,vector<vector<int>> &graph,int end){
    for(int i=0;i<end;i++){
        if(graph[i][start]==1 && color[i]==choice)
            return false;
    }
    return true;
}

bool help(int start,vector<int> &color,int m,vector<vector<int>> &graph,int end){
    if(start==end)
        return true;
    for(int i=1;i<=m;i++){
        if(if_possible(i,start,color,graph,end)){
            color[start]=i;
            int short_ans=help(start+1,color,m,graph,end);
            if(short_ans)
                return true;
            color[start]=0;
        }
    }
    
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    int e=mat.size();
    int v=mat[0].size();
    
    
    vector<int> color(v);
    bool ans=help(0,color,m,mat,v);
    if(ans)
        return "YES";
    return "NO";
}
