#include<bits/stdc++.h>
bool areAnagram(string &s, string &s2){
    // Write your code here.
    unordered_map<char,int> x;
    for(int i=0;s[i]!='\0';i++){
        
        if(x.find(s[i])!=x.end())
            x[s[i]]++;
        else
            x[s[i]]=1;
    }
    
    for(int i=0;s2[i]!='\0';i++){
        if(x.find(s2[i])!=x.end()){
            x[s2[i]]--;
        }
        else
            return false;
    }
    
    
    for(auto it:x){
        if(it.second!=0)
            return false;
    }
    
    return true;
    
}
