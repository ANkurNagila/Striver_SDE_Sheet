#include<bits/stdc++.h>
int compareVersions(string a, string b) 
{
    // Write your code here
    stringstream x(a);
    stringstream y(b);
    string str1,str2;
    
    while(getline(x,str1,'.') && getline(y,str2,'.')){
        int size1=str1.size();
        int size2=str2.size();
        
        int ele=stoi(str1);
        int ele2=stoi(str2);
        cout<<ele<<" "<<ele2<<endl;
        
        if(size1>size2)
            ele2=ele2+10*(size1-size2);
        else if(size1<size2)
            ele2=ele2+10*(size2-size1);
            
        
        if(ele>ele2)
                return 1;
        else if(ele<ele2)
                return -1;
    }
    
    while(getline(x,str1,'.')){
        int ele=stoi(str1);
        cout<<ele<<endl;
        if(ele>0)
            return 1;
    }
    
    while(getline(y,str2,'.')){
        int ele=stoi(str2);
        cout<<ele<<endl;
        if(ele>0)
            return -1;
    }
    
    return 0;
}
