#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    int n=matrix.size(),m=matrix[0].size();
    int maxi=matrix[0][0],mini=matrix[0][0];
    
    for(int i=0;i<n;i++){
        maxi=max(maxi,matrix[i][m-1]);
        mini=min(mini,matrix[i][0]);        
    }
    
    int ele=(n*m+1)/2;
    while (mini < maxi) {
        int mid = mini + (maxi - mini) / 2;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += upper_bound(&matrix[i][0], &matrix[i][m], mid) - &matrix[i][0];
        if (cnt < ele)
            mini = mid + 1;
        else
            maxi = mid;
    }
    return mini;
    
}
