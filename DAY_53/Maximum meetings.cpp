#include<bits/stdc++.h>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<vector<int>> x;
    for(int i=0;i<start.size();i++)
        x.push_back({end[i],i,start[i]});
    
    sort(x.begin(),x.end());
    vector<int> ans;
    int last;
    for(int i=0;i<x.size();i++){
        if(i==0){
            ans.push_back(x[0][1]+1);
            last=x[0][0];
        }
        else{
            if(x[i][2]>last){
                ans.push_back(x[i][1]+1);
                last=x[i][0];
            }
            else
                continue;
        }
    }
    
    return ans;
}
