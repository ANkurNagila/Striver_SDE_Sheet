#include<bits/stdc++.h>
void help(int **arr,int x,int y,int n,int m,set<pair<int,int>> &ans){
    if(x>n||x<0||y>m||y<0||arr[x][y]!=1||ans.find({x,y})!=ans.end())
        return ;
    
    ans.insert({x,y});
    
    int a=x-1,b=y-1,c=x+1,d=y+1;
    if(a>=0 && b>=0)
        help(arr,a,b,n,m,ans);
    if(a>=0)
        help(arr,a,y,n,m,ans);
    if(b>=0)
        help(arr,x,b,n,m,ans);
    if(a>=0 && d<m)
        help(arr,a,d,n,m,ans);
    if(d<m)
        help(arr,x,d,n,m,ans);
    if(c<n)
        help(arr,c,y,n,m,ans);
    if(c<n && b>=0)
        help(arr,c,b,n,m,ans);
    if(c<n && d<m)
        help(arr,c,d,n,m,ans);
    
    return ;
}

int getTotalIslands(int** arr, int n, int m)
{
    set<pair<int,int>> x;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                if(x.find({i,j})!=x.end())
                    continue;
                else{
                    ans+=1;
                    help(arr,i,j,n,m,x);
                }
            }
        }
    }
    
    return ans;
}
