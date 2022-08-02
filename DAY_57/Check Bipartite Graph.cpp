#include<bits/stdc++.h>
bool bfs(int start,vector<vector<int>> &edges,int n,vector<int> &color){
    queue<int> x;
    x.push(start);
    if(color[start]==-1)
        color[start]=0;
    
    while(x.size()!=0){
        int size=x.size();
        while(size--){
            for(int i=0;i<n;i++){
                if(i==x.front())
                    continue;
                if(edges[x.front()][i]==1){
                    if(color[i]==-1){
                        color[i]=color[x.front()]^1;
                        x.push(i);
                    }
                    //cout<<x.front()<<" "<<i<<" "<<color[i]<<endl;
                    if(color[i]!=(color[x.front()]^1))
                        return false;
                    
                }
            }
            
            x.pop();
        }
    }
    
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n=edges.size();
    vector<int> color(n,-1);
    
    for(int i=0;i<n;i++){
        bool ans=bfs(i,edges,n,color);
        if(!ans)
            return ans;
    }
    
    return true;
}
