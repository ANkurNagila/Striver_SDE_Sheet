#include<bits/stdc++.h>
int calculateMinPatforms(int a[], int d[], int n) {
    vector<int> at(n),dt(n);
    
    for(int i=0;i<n;i++){
        at[i]=a[i];
        dt[i]=d[i];
    }
    sort(at.begin(),at.end());
    sort(dt.begin(),dt.end());
    
    int i=1,j=0;
    int maxi=1;
    int plat=1;
    while(i<n){
        if(at[i]<=dt[j]){
            plat++;
            maxi=max(maxi,plat);
            i++;
        }
        else{
            plat--;
            j++;
        }
    }
    
    return maxi;
}
