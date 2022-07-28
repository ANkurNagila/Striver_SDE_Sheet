#include<bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs){
    vector<pair<int,int>> x;
    int n=0;
    for(auto it:jobs){
        x.push_back({it[1],it[0]});
        n=max(n,it[0]);
    }
    
    sort(x.begin(),x.end());
    vector<int> ans(n+1,-1);
    int res=0;
    int j=jobs.size()-1;
    while(j>=0){
        int ele=x[j].second;
        while(ele>0 && ans[ele]!=-1)
            ele--;
        if(ele>0){
            ans[ele]=x[j].first;
            res+=x[j].first;
        }
        //cout<<ele<<" "<<ans[ele]<<endl;
        j--;
    }
    
    return res;
}
