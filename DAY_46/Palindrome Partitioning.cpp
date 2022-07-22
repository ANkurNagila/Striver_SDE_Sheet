bool ispalindrome(string s){
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j])
            return false;
    }
    
    return true;
}


void help(string s,int i,vector<vector<string>> &ans,vector<string> &temp){
    if(i==0){
        string s1=s.substr(i);
        if(ispalindrome(s1)){
            temp.push_back(s1);
            ans.push_back(temp);
            temp.pop_back();
        }
        return ;
    }
    
    string s1=s.substr(0,i);
    string s2=s.substr(i);
    
    if(ispalindrome(s2)){  
        //cout<<s2<<" ";
       temp.push_back(s2);    
       help(s1,i-1,ans,temp);
       temp.pop_back();
    }
    
    help(s,i-1,ans,temp);
}

vector<vector<string>> partition(string &s) 
{
    if(s.size()==0)
        return {{}};
    vector<vector<string>> ans;
    vector<string> temp;
    help(s,s.size()-1,ans,temp);
    return ans;
}
