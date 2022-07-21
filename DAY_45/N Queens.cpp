#include<bits/stdc++.h>
int board[11][11];

void print_queens(int N,vector<vector<int>> &ans){
    vector<int> temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            temp.push_back(board[i][j]);
    }
    ans.push_back(temp);
}


bool is_possible(int x,int y,int N){
    
    for(int i=0;i<N;i++){
        if(board[i][y]==1)
            return false;
    }
    
    for(int i=0;i<N;i++){
        if(board[x][i]==1)
            return false;
    }
    
    for(int i=x-1,j=y+1;i>=0,j<N;i--,j++){
        if(board[i][j]==1)
            return false;
    }
    
    for(int i=x-1,j=y-1;i>=0,j>=0;i--,j--){
        if(board[i][j]==1)
            return false;
    }
    
    return true;
}



void queens_place(int i,int N,vector<vector <int>> &ans){
    if(i==N){
        print_queens(N,ans);
        return ;
    }
    
    for(int j=0;j<N;j++){
        if(is_possible(i,j,N)){
            board[i][j]=1;
            queens_place(i+1,N,ans);
            board[i][j]=0;
        }
    }
    return ;   
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    memset(board,0,sizeof(board));
    queens_place(0,n,ans);
    return ans;
    
}
