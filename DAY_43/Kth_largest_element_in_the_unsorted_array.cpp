int kthLargest(vector<int>& arr, int size, int k)
{
    sort(arr.begin(),arr.end());
    return arr[size-k];
}


********************************************* Using Heap ***************************************

#include<queue>
int kthLargest(vector<int>& input, int n, int k)
{
    priority_queue<int ,vector<int> ,greater<int>> x;
    
    for(int i=0;i<k;i++)
        x.push(input[i]);
    
    for(int i=k;i<n;i++){
        if(x.top()<input[i]){
            x.pop();
            x.push(input[i]);
        }
    }
    
    return x.top();
}
