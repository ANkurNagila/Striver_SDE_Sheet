#include <bits/stdc++.h> 
void rotateMatrix(vector<vector<int>> &arr, int n, int m)
{
    int row=n-1,col=m-1;
    int s_r=0,s_c=0;
    
    while(s_r<row && s_c<col){
        int temp=arr[s_r][row];
        
        int j=s_r;
        for(int i=s_c;i<col;i++)
            swap(temp,arr[j][i]);
        
        j=col;
        for(int i=s_r;i<row;i++)
            swap(temp,arr[i][j]);
        
        j=row;
        for(int i=col;i>s_c;i--)
            swap(temp,arr[j][i]);
        
        j=s_c;
        for(int i=row;i>s_r;i--)
            swap(temp,arr[i][j]);
        
        arr[s_r][s_c]=temp;
        s_r++;
        s_c++;
        row--;
        col--;   
    }
}
