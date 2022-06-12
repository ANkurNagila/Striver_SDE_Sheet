#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code here
    if(s.size()<=1)
        return s.size();
    
    int index=0;
    int ans=1;
    int sum=1;
    unordered_set<char> x;
    
    for(int i=0;s[i]!='\0';i++){
        if(x.find(s[i])!=x.end()){
            for(;s[index]!=s[i];index++){
                x.erase(s[index]);
            }
            index++;
            sum=i-index+1;
        }
        else{
            sum=i-index+1;
            x.insert(s[i]);
            if(sum>ans)
                ans=sum;
        }
    }
    if(sum>ans)
       ans=sum;
    
    return ans;
}
