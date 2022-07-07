vector<string> ans;

void help(string &s,int i){
    if(i==s.size()){
        ans.push_back(s);
        return ;
    }
    
    for(int j=i;s[j]!='\0';j++){
        swap(s[i],s[j]);
        help(s,i+1);
        swap(s[i],s[j]);
    }
}

vector<string> findPermutations(string &s) {
    help(s,0);
    return ans;
}
