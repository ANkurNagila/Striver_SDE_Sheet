bool check(string &str,string &pat,int x,int y){
    for(int i=x,j=0;i<y;i++,j++){
        if(str[i]!=pat[j])
            return false;
    }
    
    return true;
} 

vector<int> stringMatch(string &str, string &pat) {
    vector<int> x;
    int l=pat.size();
    for(int i=0;i<str.size();i++){
        if(check(str,pat,i,i+l)){
            x.push_back(i);
        }
    }
    
    return x;
}
