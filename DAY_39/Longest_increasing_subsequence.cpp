#include<bits/stdc++.h>
int longestIncreasingSubsequence(int nums[], int n)
{
        vector<int> dp(n,INT_MAX);
        int count=0;
        for(int i=0;i<n;i++){
            int ind=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            dp[ind]=nums[i];
        }
    
        for(int i=0;i<n;i++){
            if(dp[i]==INT_MAX)break;
            else count++;
        }
        return count;
}
