#include<bits/stdc++.h>
int romanToInt(string s) {
    int ans=0;
    int temp=0;
    
    unordered_map<char,int> x;
    x['I']=1;
    x['V']=5;
    x['X']=10;
    x['L']=50;
    x['C']=100;
    x['D']=500;
    x['M']=1000;
    
    for(int i=0;s[i]!='\0';i++){
        int ele=x[s[i]];
        if(ele<=temp){
            ans+=temp;
            temp=ele;
        }
        else{
            temp=ele-temp;
        }
    }
    
    if(temp!=0)
        ans+=temp;
    
    return ans;
}
