#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> x;
    int n=start.size();
    
    if(n==0)
        return 0;
    
    for(int i=0;i<n;i++){
        x.push_back({finish[i],start[i]});
    }
    
    sort(x.begin(),x.end());
    int ans=1;
    int last=x[0].first;
    
    for(int i=1;i<n;i++){
        if(last<=x[i].second){
            ans++;
            last=x[i].first;
        }
    }
    
    return ans;
}
