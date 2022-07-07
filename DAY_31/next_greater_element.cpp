#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> x;
    x.push(-1);
    x.push(arr[n-1]);
    
    vector<int> ans(n);
    ans[n-1]=-1;
    
    for(int i=n-2;i>=0;i--){
        if(x.top()<=arr[i]){
            while(x.top()!=-1 && x.top()<=arr[i]){
                x.pop();
            }
            ans[i]=x.top();
            x.push(arr[i]);
        }
        else{
            ans[i]=x.top();
            x.push(arr[i]);
        }
    }
    return ans;
}
