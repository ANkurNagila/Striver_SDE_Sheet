#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int total=(n*(n+1))/2;
    unordered_set<int> x;
    int dup=0,sum=0,flag=0;;
    
    for(int i=0;i<n;i++){
        if(flag==0){
            if(x.find(arr[i])!=x.end()){
                dup=arr[i];
                flag=1;
            }
            else
                x.insert(arr[i]);
        }
        sum+=arr[i];        
    }
    sum=sum-dup;
    return make_pair(total-sum,dup);
}
