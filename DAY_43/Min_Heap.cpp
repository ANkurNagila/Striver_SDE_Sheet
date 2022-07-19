void remove(vector<int> &ans,vector<int> &temp){
    if(ans.size()==0)
        return ;
    
    int child=ans.size()-1;
    int root=0;
    
    swap(ans[child],ans[root]);
    int ele=ans[child];
    temp.push_back(ele);
    
    ans.pop_back();
    while(root<ans.size()){
        int child1=2*root+1;
        int child2=2*root+2;
        
        if(child2<ans.size()){
            if(ans[child1]<ans[root]||ans[child2]<ans[root]){
                if(ans[child1]<ans[child2]){
                    swap(ans[child1],ans[root]);
                    root=child1;
                }
                else{
                    swap(ans[child2],ans[root]);
                    root=child2;
                }
            }
            else{
                break;
            }
        }
        else{
                if(child1<ans.size()){
                    if(ans[child1]<ans[root]){
                        swap(ans[child1],ans[root]);
                        root=child1;
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }
}

void insert(vector<int> &ans,int e){
    ans.push_back(e);  
    
    int i=ans.size()-1;
    while(i>0){
        int parent=(i-1)/2;
        if(ans[parent]>ans[i]){
            swap(ans[parent],ans[i]);
            i=parent;
        }
        else
            break;
    }
    
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    if(n==0)
        return {};
    
    vector<int> ans;
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(q[i][0]==1)
            remove(ans,temp);
        else
            insert(ans,q[i][1]);
    }
    
    return temp;
}
