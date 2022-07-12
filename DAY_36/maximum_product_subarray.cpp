#include<bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    int a=arr[0],b=arr[0],ans=arr[0];
    
    for(int i=1;i<n;i++){
        int temp=max({ arr[i] , a*arr[i] , b*arr[i] });
        b=min({ arr[i] , a*arr[i] , b*arr[i] });
        
        a=temp;
        ans=max(a,ans);
        
    }
    
    return ans;    
}
