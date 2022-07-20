#include<queue>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<int,vector<int>,greater<int> > x;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x.size()<k){
                x.push(a[i]+b[j]);
            }
            else{
                if(x.top()<(a[i]+b[j])){
                    x.pop();
                    x.push(a[i]+b[j]);
                }
            }
        }
    }
    
    vector<int> ans(k);
    int i=k-1;
    while(x.size()!=0){
        ans[i--]=x.top();
        x.pop();
    }
    return ans;
}
