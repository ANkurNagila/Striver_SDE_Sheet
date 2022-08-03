#include<bits/stdc++.h>
int compareVersions(string a, string b) 
{
    // Write your code here
    int asize=a.length();
    int bsize=b.length();

    vector<string> anum;
    vector<string> bnum;
    string temp="";
    for(int i=0;i<asize;i++){


        if(a[i]=='.'){
            anum.push_back(temp);
            temp="";
        }else{
            temp+=a[i];
        }
    }
    anum.push_back(temp);
    temp="";
    
    for(int i=0;i<bsize;i++){
        
        if(b[i]=='.'){
            bnum.push_back(temp);
            temp="";
        }else{
            temp+=b[i];
        }
    }
    bnum.push_back(temp);
    temp="";
    
    int n=anum.size();
    int m=bnum.size();
    

    
    int maxl=max(n,m);
    
    for(int i=0;i<maxl;i++){
        string v1=i<n?anum[i]:"0";
        string v2=i<m?bnum[i]:"0";
        if(v1 > v2){
            if(v2.size()>v1.size()){
                return -1;
            }else{
                return 1;
            }
        }else if(v2 > v1){ 
            if(v1.size()>v2.size()){ 
                return 1;
            }else{
                return -1;
            }

        }
    }
    return 0;

}
