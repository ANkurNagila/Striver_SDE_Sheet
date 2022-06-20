#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
    long long ans=1;
    long long a;
    a=x%m;
    
    while(n>0){
        if(n & 1)
            ans=((ans%m)*(a%m))%m;
        a= ((a % m)* (a % m))%m;
        n=n>>1;
    }
    
    return ans%m;
    
}
