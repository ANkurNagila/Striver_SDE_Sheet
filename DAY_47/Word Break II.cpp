#include<bits/stdc++.h>

void help(string &s,int i,unordered_set<string> &x,string temp,vector<string> &ans){
    if(i<=0){
        string s1=s.substr(0);
        if(x.find(s1)!=x.end()){
            temp=s1+" "+temp;
            ans.push_back(temp);
        }
        
        return ;
    }
    
    string s1=s.substr(0,i);
    string s2=s.substr(i);
    
    string prev=temp;
    if(x.find(s2)!=x.end()){
        temp=s2+" "+temp;
        help(s1,i-1,x,temp,ans);
    }
    
    help(s,i-1,x,prev,ans);
    
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    if(dictionary.size()==0)
        return ans;
    
    unordered_set<string> x;
    for(auto it:dictionary)
        x.insert(it);
    
    string temp="";
    help(s,s.size()-1,x,temp,ans);
    
    return ans;
}
