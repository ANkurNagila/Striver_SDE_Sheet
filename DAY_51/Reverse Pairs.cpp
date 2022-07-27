#include <bits/stdc++.h>
int merge(vector<int>& num, int low, int mid, int high){
        int n1 = mid - low + 1;
        int n2 = high - mid;

        int l[n1], r[n2];
        for(int i=0;i<n1;i++) l[i] = num[low + i];
        for(int i=0;i<n2;i++) r[i] = num[mid + 1 + i];

        int j=0;
        int count=0;
        for(int i=0;i<n1;i++){
            while(j<n2 && (l[i] > 2LL*r[j])){
                j++;
            }
            count += j;
        }
        int i=0,k = low;
        j=0;
        while(i < n1 && j < n2){
            if(l[i]<=r[j]) num[k++] = l[i++];
            else num[k++] = r[j++];
        }
        while(i<n1) num[k++] = l[i++];
        while(j<n2) num[k++] = r[j++];

    return count;
}

int merge_sort(vector<int> &arr,int start,int end){
    if(start>=end)
        return 0;
    
    int mid=(start+end)/2;
    
    int count=0;
    count+=merge_sort(arr,start,mid);
    count+=merge_sort(arr,mid+1,end);
    count+=merge(arr,start,mid,end);
    return count;

}


int reversePairs(vector<int> &arr, int n){
    int ans=0;
    ans=merge_sort(arr,0,n-1);
    
    return ans;
}
