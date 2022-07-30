#include<bits/stdc++.h>
int dp[103][103];

int help(vector<int> &arr,int start,int end){
    if(start>=end)
        return 0;
    
    if(dp[start][end]!=-1)
        return dp[start][end];
    
    dp[start][end]=INT_MAX;
    for(int k=start;k<end;k++){
        dp[start][end]=min(dp[start][end],help(arr,start,k)+help(arr,k+1,end)+ arr[start-1]*arr[end]*arr[k]);
    }
    
    return dp[start][end];
    
}

int matrixMultiplication(vector<int> &arr, int n)
{
    int start=1,end=n-1;
    memset(dp,-1,sizeof(dp));
    return help(arr,start,end);
    
}
