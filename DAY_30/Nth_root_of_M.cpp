double findNthRootOfM(int n, long long m) {
    return pow(m,(double)(1.0/n));
}


/***************************Binary_Search(Alternative)***************************/

double mul(double x,int n){
    double i=1.0;
    for(int j=1;j<=n;j++)
        i=i*x;
    return i;
}

double findNthRootOfM(int n, long long m) {
    double first=1,last=m;
    double a=1e-9;
    double mid;
    
    while(last-first>a){
        mid=(last+first)/2.0;
        
        if(mul(mid,n)>m)
            last=mid;
        else
            first=mid;
    }
    return first;
}
