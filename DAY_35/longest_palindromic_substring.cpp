int help_check(string s,int i,int j){
    if(s.size()==0)
        return 0;
    
    while(i>=0 && j<s.size()){
        if(s[i]!=s[j])
            break;
        i--;
        j++;
    }
    
    return j-i-1;
}

string longestPalinSubstring(string s)
{
    int start=0;
    int maxi=0;
    
    for(int i=0;i<s.size();i++){
        int ele_1=help_check(s,i,i);
        int ele_2=help_check(s,i,i+1);
        int best=max(ele_1,ele_2);
        
        if(best>maxi){
            start= i-(best-1)/2;
            maxi=best;
        }
    }
    
    return s.substr(start,maxi);
}
