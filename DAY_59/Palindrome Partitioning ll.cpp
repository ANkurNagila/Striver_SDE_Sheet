#include<bits/stdc++.h>
bool isPalindrome(int start,int end,string str){
    while(start<end){
        if(str[start]!=str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int help(int start,int end,string str,vector<int> &dp){
    if(start==end)
        return 0;
    
    if(dp[start]!=-1)
        return dp[start];
    
    int mincost=INT_MAX;
    for(int i=start;i<end;i++){
        if(isPalindrome(start,i,str)){
            int cost=1+help(i+1,end,str,dp);
            mincost=min(cost,mincost);
        }
    }
    
    return dp[start]=mincost;
}


int palindromePartitioning(string str) {
    int n=str.size();
    
    vector<int> dp(n,-1);
    return help(0,n,str,dp)-1;
}
