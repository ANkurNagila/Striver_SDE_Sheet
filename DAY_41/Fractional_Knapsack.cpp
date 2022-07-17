#include<bits/stdc++.h>
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    if(n==0)
        return 0;
    
    vector<pair<double,int>> x;
    
    for(int i=0;i<n;i++){
        double ele=((items[i].second)*1.0)/(items[i].first);
        x.push_back(make_pair(ele,i));
    }
    
    double ans=0;
    sort(x.begin(),x.end());
    
    for(int i=n-1;i>=0 && w>0;i--){
        int ele=x[i].second;
        if(w>=items[ele].first){
            ans+=items[ele].second;
            w-=items[ele].first;
        }
        else{
            ans+=(x[i].first*w);
            w=0;
        }
    }
    
    return ans;
}
