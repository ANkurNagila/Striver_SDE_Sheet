int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    int dp[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        int ele=0;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i])
                ele=max(ele,dp[j]);
        }
        dp[i]=ele+arr[i];
        maxi=max(maxi,dp[i]);
    }
    
    return maxi;
}
