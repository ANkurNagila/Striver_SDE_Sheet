#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n)
{
    int size=price.size();
    int dp[size+1][n+1];
    int length[size];
    
    memset(dp,0,sizeof(dp));
    
    for(int i=1;i<size+1;i++){
        for(int j=1;j<n+1;j++){
            if(j>=i){
                dp[i][j]=max((price[i-1]+dp[i][j-i]),dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[size][n];
}
