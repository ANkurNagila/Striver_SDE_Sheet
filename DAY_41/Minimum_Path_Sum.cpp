int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m=grid.size(),n=grid[0].size();
        
        if(m==0||n==0)
            return 0;
        
        int arr[m][n];
        
        arr[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    continue;
                
                if(i==0)
                    arr[i][j]=arr[i][j-1]+grid[i][j];
                if(j==0)
                    arr[i][j]=arr[i-1][j]+grid[i][j];
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                arr[i][j]=min(arr[i-1][j],arr[i][j-1])+grid[i][j];
            }
        }
        
        return arr[m-1][n-1];
}
