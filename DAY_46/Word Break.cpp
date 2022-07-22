#include<bits/stdc++.h>
bool help(unordered_set<string> &x,int n,int i,string &target){
    if(i==0){
        if(target.size()==0)
            return true;
        else{
            if(x.find(target)!=x.end())
                return true;
            return false;
        }
    }
    
    bool ans;
    string s1=target.substr(0,i);
    string s2=target.substr(i);
    //cout<<i<<" "<<s1<<" "<<s2<<endl;
    
    if(x.find(s2)!=x.end()){
        ans=help(x,n,i-1,s1);
    }
    else{
        ans=help(x,n,i-1,target);
    }
    return ans;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_set<string> x;
    for(auto it:arr)
        x.insert(it);
    
    int N=target.size();
    return help(x,N,N,target);
}
