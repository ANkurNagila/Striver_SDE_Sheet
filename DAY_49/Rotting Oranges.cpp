#include<queue>
int minTimeToRot(vector<vector<int>>& arr, int n, int m)
{
    queue<pair<int,int>> x;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==2)
                x.push({i,j});
        }
    }
    
    int count=0;
    while(x.size()!=0){
        int size=x.size();
        count++;
        while(size--){
            int i=x.front().first,j=x.front().second;
            
            if(i-1>=0 && arr[i-1][j]==1){
                x.push({i-1,j});
                arr[i-1][j]=2;
            }
            if(i+1<n && arr[i+1][j]==1){
                x.push({i+1,j});
                arr[i+1][j]=2;
            }
            if(j-1>=0 && arr[i][j-1]==1){
                x.push({i,j-1});
                arr[i][j-1]=2;
            }
            if(j+1<m && arr[i][j+1]==1){
                x.push({i,j+1});
                arr[i][j+1]=2;
            }            
            x.pop();
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1)
                return -1;
        }
    }
    
    
    if(count==0)
        return 0;
    return count-1;
}
