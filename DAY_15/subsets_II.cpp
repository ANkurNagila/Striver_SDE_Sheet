#include<bits/stdc++.h>
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>> data;
    vector<vector<int>> ans;
    data.insert({});
    ans.push_back({});
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++){
        int size=ans.size();
        for(int j=0;j<size;j++){
            vector<int> temp=ans[j];
            temp.push_back(arr[i]);
            if(not(data.find(temp)!=data.end())){
                ans.push_back(temp);
                data.insert(temp);
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}
