#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    unordered_map<int,int> x;
    
    vector<int> ans;
    for(int i=0;i<k;i++){
        x[arr[i]]++;
    }
    int count=0;
    for(auto it:x){
        if(it.second>=1)
            count++;
    }
    ans.push_back(count);
    
    for(int i=1;i<arr.size()-k+1;i++){
        x[arr[i-1]]--;
        x[arr[i+k-1]]++;
        count=0;
        for(auto it:x){
            if(it.second>=1)
                count++;
        }
        ans.push_back(count);
    }
    
    return ans;
}
