#include<bits/stdc++.h>
void help(vector<int> &arr,vector<vector<int>> &ans,vector<int> &temp,int start,int end,int target){
    if(target==0){
        ans.push_back(temp);
        return ;
    }
    
    for(int i=start;i<end;i++){
        if(i>start && arr[i]==arr[i-1])
            continue;
        
        if(arr[i]>target)
            break;
        
        temp.push_back(arr[i]);
        help(arr,ans,temp,i+1,end,target-arr[i]);
        temp.pop_back();
    }
    
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(),arr.end());
    
    help(arr,ans,temp,0,n,target);
    
    return ans;
}
