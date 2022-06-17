#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & arr, int m, int n, int target) {
    // Write your code here
    int low=0;
    int high=n*m-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        int i=mid/n;
        int j=mid%n;
        
        if(arr[i][j]==target)
            return true;
        else if(arr[i][j]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    
    return false;
}
