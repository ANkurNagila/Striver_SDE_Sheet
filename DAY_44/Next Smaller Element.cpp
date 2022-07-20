#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> x;
    vector<int> y(n);
    
    for(int i=n-1;i>=0;i--){
        if(x.size()==0){
            y[i]=-1;
            x.push(arr[i]);
        }
        else{
            if(x.top()>=arr[i]){
                while(x.size()>0 && x.top()>=arr[i])
                    x.pop();
                
                if(x.size()==0){
                    y[i]=-1;
                    x.push(arr[i]);
                }
                else{
                    y[i]=x.top();
                    x.push(arr[i]);
                }
            }
            else{
                y[i]=x.top();
                x.push(arr[i]);
            }
        }
    }
    
    return y;
}
