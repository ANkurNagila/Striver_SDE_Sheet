#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> x;
    int maxi=1,temp=0;
    
    for(auto it: arr)
        x.insert(it);
    
    for(auto it:arr){
        if(x.find(it-1)!=x.end())
            continue;
        else{
            int temp=1;
            int ele=it+1;
            
            while(x.find(ele++)!=x.end())
                temp++;
            
            maxi=max(maxi,temp);
        }
    }
    return maxi;
}
