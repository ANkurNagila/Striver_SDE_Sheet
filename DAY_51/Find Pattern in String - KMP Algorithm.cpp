void prefix_table(vector<int> &table,string s,int n){
    table[0]=0;
    int i=1,j=0;
    
    while(i<n){
        if(s[i]==s[j]){
            table[i]=j+1;
            j++;
            i++;
        }
        else if(j>0){
            j=table[j-1];
        }
        else{
            table[i]=0;
            i++;
        }
    }
}

bool findPattern(string s, string p)
{
    int m=p.size(),n=s.size();
    vector<int> table(n);
    prefix_table(table,s,n);
    
    int i=0,j=0;
    while(i<m){
        if(p[i]==s[j]){
            if(j==n-1)
                return true;
            else{
                i++;
                j++;
            }
        }
        else if(j>0){
            j=table[j-1];
        }
        else{
            i++;
        }
    }
    
    return false;
}
