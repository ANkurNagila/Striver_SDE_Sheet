#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long last[n],first[n];
    long maxi=arr[0];
    first[0]=maxi;
    for(int i=1;i<n;i++){
        if(arr[i]>maxi)
            maxi=arr[i];
        first[i]=maxi;
    }
    
    maxi=arr[n-1];
    last[n-1]=maxi;
    for(int j=n-2;j>=0;j--){
        if(arr[j]>maxi)
            maxi=arr[j];
        last[j]=maxi;
    }
    
    long ans=0;
    for(int i=0;i<n;i++){
        ans+=min(first[i],last[i])-arr[i];
    }
    
    return ans;
    
}
