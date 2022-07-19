#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&input, int k)
{
    priority_queue<int,vector<int>,greater<int>> x;
    
    for(int i=0;i<k;i++){
        for(int j=0;j<input[i].size();j++){
            x.push(input[i][j]);
        }
    }
    
    vector<int> ans;
    while(x.size()!=0){
        ans.push_back(x.top());
        x.pop();
    }
        
    return ans;
    
}
