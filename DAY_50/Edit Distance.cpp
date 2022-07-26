int editDistance(string str1, string str2)
{
    int n=str1.size(),m=str2.size();
    int dp[n+1][m+1];
    
    for(int i=0;i<n+1;i++)
        dp[i][0]=i;
    
    for(int i=0;i<m+1;i++)
        dp[0][i]=i;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
        }
    }
    
    return dp[n][m];
}
