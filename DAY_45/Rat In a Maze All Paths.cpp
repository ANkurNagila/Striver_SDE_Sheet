#include<bits/stdc++.h>
int ans[11][11];
void print_path(int N,vector<vector<int>> &res){
    vector<int> temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            temp.push_back(ans[i][j]);
        }
    }
    
    res.push_back(temp);
}


void place(vector<vector <int>> &board,int i,int j,int N,vector<vector<int>> &res){
    if(i<0 || i>=N || j<0 || j>=N)
        return ;
    
    if(i==N-1 && j==N-1){
        ans[i][j]=1;
        print_path(N,res);
        ans[i][j]=0;
        return ;
    }
    
    if(board[i][j]==0)
        return ;
    
    ans[i][j]=1;
    int up=i-1,down=i+1,left=j-1,right=j+1;
    
    if(up>=0 && ans[up][j]!=1)
        place(board,up,j,N,res);
    if(down<N && ans[down][j]!=1)
        place(board,down,j,N,res);
    if(left>=0 && ans[i][left]!=1)
        place(board,i,left,N,res);
    if(right<N && ans[i][right]!=1)
        place(board,i,right,N,res);
    ans[i][j]=0;
    
    return ;
    
}


vector<vector<int> > ratInAMaze(vector<vector<int> > &board, int N){
  // Write your code here.
    vector<vector<int>> res;
    memset(ans,0,sizeof(ans));
    place(board,0,0,N,res);

    return res;
}
