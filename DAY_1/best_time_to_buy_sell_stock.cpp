#include <bits/stdc++.h> 
int maximumProfit(vector<int> &arr){
    if(arr.size()<=1)
        return 0;
    
    int mini=arr[0],maxi=arr[0];
    int ans=0;
    
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxi)
            maxi=arr[i];
        
        ans=max(ans,maxi-mini);
        
        if(arr[i]<mini){
            mini=arr[i];
            maxi=arr[i];
        }
    }
    
    ans=max(ans,maxi-mini);
    return ans;
   
}
