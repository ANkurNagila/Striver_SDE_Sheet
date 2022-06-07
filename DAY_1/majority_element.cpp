#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    if(n==1)
        return arr[0];
    
    unordered_map<int,int> x;
    
    int mid=n/2;
    if(n%2!=0)
        mid=(n-1)/2;

    for(int i=0;i<n;i++){
        if(x.find(arr[i])!=x.end()){
            x[arr[i]]++;
            if(x[arr[i]]>mid)
                return arr[i];
        }
        else
            x[arr[i]]=1;
    }
    
    return -1;
}
