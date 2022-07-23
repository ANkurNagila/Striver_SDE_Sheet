string kthPermutation(int n, int k) {
    if(n==0)
        return "";
    
    vector<int> arr;
    for(int i=1;i<=n;i++)
        arr.push_back(i);
    
    int fact=1;
    for(int i=1;i<n;i++)
        fact=fact*i;
    
    string ans="";
    k=k-1;
    while(true){
        int ele=k/fact;
        ans=ans+to_string(arr[ele]);
        arr.erase(arr.begin()+ele);
        
        if(arr.size()==0)
            break;
        
        k=k%fact;
        fact=fact/arr.size();
    }
    
    return ans;

}
