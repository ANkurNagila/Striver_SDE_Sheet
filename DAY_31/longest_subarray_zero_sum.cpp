#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int> x;
    int sum=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==0){
            ans=i+1;
        }
        else{
            if(x.find(sum)!=x.end())
                ans=max(ans,i-x[sum]);
            else
                x[sum]=i;
        }
    }
    
    return ans;
}
