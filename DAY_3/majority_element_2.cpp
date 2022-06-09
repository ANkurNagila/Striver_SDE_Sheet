#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
  
    unordered_map<int,int> x;
    for(auto it:arr){
        if(x.find(it)!=x.end())
            x[it]++;
        else
            x[it]=0;
    }
    
    int n=arr.size();
    int temp=n/3;
    vector<int> ans;
    
    for(auto it:x){
        if(it.second>=temp)
            ans.push_back(it.first);
    }
    
    return ans;
}
