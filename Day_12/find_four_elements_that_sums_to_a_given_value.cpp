#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++){
        int ele=target-arr[i];
        for(int j=i+1;j<n;j++){
            int ele2=ele-arr[j];
            int first=j+1;
            int last=n-1;
            
            while(first<last){
                if(ele2<(arr[first]+arr[last]))
                    last--;
                else if(ele2>(arr[first]+arr[last]))
                    first++;
                else
                    return "Yes";
            }
            while(j+1<n && arr[j]==arr[j+1]) ++j;
        }
        while(i+1<n && arr[i]==arr[i+1]) ++i;
    }
    
    return "No";
}
