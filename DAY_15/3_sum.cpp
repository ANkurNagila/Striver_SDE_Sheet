#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int k) {
    vector<vector<int>> ans;
    if(n<3)
        return ans;
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n-2;i++)
    {
        int ele=k-arr[i];
        if(i==0 || (i>0 && arr[i]!=arr[i-1])){
            int low=i+1;
            int high=n-1;
            
            while(low<high){
                int sum=arr[low]+arr[high];
                if(ele>sum)
                    low++;
                else if(ele<sum)
                    high--;
                else
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    ans.push_back(temp);
                    
                    while(low<high && arr[low]==arr[low+1])low++;
                    while(low<high && arr[high]==arr[high-1])high--;
                    
                    low++;
                    high--;
                }
            }
        }
    }
    return ans;
}
