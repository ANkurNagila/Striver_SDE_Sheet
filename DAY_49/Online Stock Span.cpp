#include<stack>
vector<int> findSpans(vector<int> &price) {
    int n=price.size();
    if(n==0)
        return {};
    
    stack<int> x;
    vector<int> ans;
    int maxi;
    for(int i=0;i<n;i++){
        if(i==0){
            x.push(0);
            ans.push_back(1);
        }
        else{
            while(x.size()!=0 && price[x.top()]<=price[i])
                x.pop();
            
            if(x.size()==0)
                ans.push_back(i+1);
            else
                ans.push_back(i-x.top());
            
            x.push(i);
            
        }
    }
    
    return ans;
}
