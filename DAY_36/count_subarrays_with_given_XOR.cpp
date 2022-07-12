#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int t)
{
    int ans=0;
    unordered_map<int,int> x;
    x[0]=1;
    
    int ele=0;
    if(arr[0]!=0)
        x[arr[0]]=1;
    else
        x[0]+=1;
    
    ele^=arr[0];
    if(x.find(ele^t)!=x.end()){
        if((ele^t)!=ele)
            ans+=x[ele^t];
        else
            ans+=(x[ele^t]-1);
    }
    
    for(int i=1;i<arr.size();i++){
        ele^=arr[i];
        if(x.find(ele)!=x.end())
            x[ele]++;
        else
            x[ele]=1;
        
        if(x.find(ele^t)!=x.end()){
            if((ele^t)!=ele)
                ans+=x[ele^t];
            else
                ans+=(x[ele^t]-1);
        }
    }
    
    return ans;
}
