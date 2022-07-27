#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int N=m+n;
    
    if(m>n)
        return ninjaAndLadoos(row2,row1,n,m,k);
    
    int low=0,high=m;
    while(low<=high){
        //cout<<low<<" "<<high<<":";
        int cut1=(low+high)/2;
        if(k-cut1>n){
            low=cut1+1;
            continue;
        }
        else if(k-cut1<0){
            high=cut1;
            continue;
        }
        
        int cut2=k-cut1;
       // cout<<cut1<<" "<<cut2<<endl;
        
        int l1,r1,r2,l2;
            
        l1=cut1==0 ? INT_MIN : row1[cut1-1];
        r1=cut1==(m) ? INT_MAX :row1[cut1];
            
        l2=cut2==0 ? INT_MIN : row2[cut2-1];
        r2=cut2==(n) ? INT_MAX : row2[cut2];
        
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2)
            high=cut1;
        else
            low=cut1+1;
    }
    return 0;
}
