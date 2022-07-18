#include<bits/stdc++.h> 
int largestRectangle(vector < int > & arr) {
    stack<int> x;
    int n=arr.size();
    int left[n];
    int right[n];
    
    for(int i=0;i<n;i++){
        if(x.size()==0){
            left[i]=0;
            x.push(i);
        }
        else{
            if(arr[x.top()]<arr[i]){
                left[i]=x.top()+1;
                x.push(i);
            }
            else{
                while(x.size()>0 && arr[x.top()]>=arr[i])
                    x.pop();
                if(x.size()==0){
                    left[i]=0;
                    x.push(i);
                }
                else{
                    left[i]=x.top()+1;
                    x.push(i);
                }
            }
        }
    }
    
    while(x.size()>0)
        x.pop();
    
    for(int i=n-1;i>=0;i--){
        if(x.size()==0){
            right[i]=n-1;
            x.push(i);
        }
        else{
            if(arr[x.top()]<arr[i]){
                right[i]=x.top()-1;
                x.push(i);
            }
            else{
                while(x.size()>0 && arr[x.top()]>=arr[i])
                    x.pop();
                if(x.size()==0){
                    right[i]=n-1;
                    x.push(i);
                }
                else{
                    right[i]=x.top()-1;
                    x.push(i);
                }
            }
        }
    }
    
    int maxi=0;
    for(int i=0;i<n;i++){
        int area=arr[i]*(right[i]-left[i]+1);
        maxi=max(maxi,area);
    }
    
    return maxi;
 }
