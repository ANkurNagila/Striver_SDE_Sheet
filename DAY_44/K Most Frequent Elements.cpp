#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> x;
    for(auto it:arr){
        x[it]++;
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > test;
    
    for(auto it:x){
        if(test.size()<k)
            test.push({it.second,it.first});
        else{
            if(test.top().first<it.second){
                test.pop();
                test.push({it.second,it.first});
            }
        }
    }
    
    vector<int> ans(k);
    for(int i=0;i<k;i++){
        ans[i]=(test.top().second);
        test.pop();
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}
