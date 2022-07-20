#include<queue>
vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> max_heap;
    priority_queue<int ,vector<int> , greater<int>> min_heap;
    
    vector<int> ans;
    
    for(int i=0;i<n;i++){
        if(max_heap.size()==0 && min_heap.size()==0){
            max_heap.push(arr[i]);
        }
        else if(max_heap.size()>0){
            if(arr[i]<max_heap.top()){
                max_heap.push(arr[i]);
            }
            else{
                min_heap.push(arr[i]);
            }
        }
        
        
        if(((max_heap.size()-min_heap.size())>1 && max_heap.size()>min_heap.size())|| ((min_heap.size()-max_heap.size())<-1 && min_heap.size()>max_heap.size())){
            if(max_heap.size()>min_heap.size()){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else{
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        
        if(i%2==0){
            if(max_heap.size()>min_heap.size())
                ans.push_back(max_heap.top());
            else
                ans.push_back(min_heap.top());
        }
        else{
            ans.push_back((max_heap.top()+min_heap.top())/2);
        } 
    } 
    
    return ans;
}
