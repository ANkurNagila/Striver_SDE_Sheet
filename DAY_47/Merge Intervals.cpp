#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    
    for(int i=0;i<arr.size();i++){
        if(ans.size()==0)
            ans.push_back({arr[i][0],arr[i][1]});
        else{
            vector<int> temp=ans.back();
            if(temp[0]>=arr[i][0] && temp[0]<=arr[i][1]){
                if(temp[1]>arr[i][1])
                   ans[ans.size()-1][0]=arr[i][0];
                else{
                    ans[ans.size()-1][0]=arr[i][0];
                    ans[ans.size()-1][1]=arr[i][1];
                }
            }
            else if(temp[1]>=arr[i][0] && temp[1]<=arr[i][1]){
                if(temp[0]<arr[i][0]){
                    ans[ans.size()-1][1]=arr[i][1];
                }
                else{
                    ans[ans.size()-1][0]=arr[i][0];
                    ans[ans.size()-1][1]=arr[i][1];
                }
            }
            else if(arr[i][0]>temp[0] && arr[i][1]<temp[1])
                continue;
            else{
                ans.push_back({arr[i][0],arr[i][1]});
            }
        }
    }
    
    return ans;
}
