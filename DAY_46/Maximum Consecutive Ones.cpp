int longestSubSeg(vector<int> &arr , int n, int k){
    int i=0,j=0;
    int count=0;
    int ans=0;
    while(j<n){
        if(arr[j]==0)
            count++;
        j++;
        
        if(count>k){
            while(count>k && i<=j){
                if(arr[i]==0)
                    count--;
                i++;
            }
        }
        
        ans=max(ans,j-i);
    }
    
    return ans;
}
