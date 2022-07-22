bool valid(int matrix[9][9],int x,int y,int k){
    
    for(int i=0;i<9;i++){
        if(matrix[i][y]==k)
            return false;
    }
    
    for(int i=0;i<9;i++){
        if(matrix[x][i]==k)
            return false;
    }
    
    int a=(x/3)*3;
    int b=(y/3)*3;
    
    for(int i=a;i<a+3;i++){
        for(int j=b;j<b+3;j++){
            if(matrix[i][j]==k)
                return false;
        }
    }
    
    return true;
    
}

bool find_empty(int matrix[9][9],int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    int row,col;
    if(!find_empty(matrix,row,col)){
        return true;
    }
    
    for(int i=1;i<=9;i++){
        if(valid(matrix,row,col,i)){
            matrix[row][col]=i;
            if(isItSudoku(matrix))
                return true;
        }
        matrix[row][col]=0;
    }      
    return false;
}
