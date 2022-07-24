#include<bits/stdc++.h>
double median(vector<int> nums1, vector<int> nums2)
{
    int size1=nums1.size();
        int size2=nums2.size();
        
        if(size2<size1)
            return median(nums2,nums1);
        
        int n=size1+size2;
        int low=0,high=size1;
        
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=((n+1)/2)-cut1;
            
            int l1,r1,r2,l2;
            
            l1=cut1==0 ? INT_MIN : nums1[cut1-1];
            r1=cut1==(size1) ? INT_MAX :nums1[cut1];
            
            l2=cut2==0 ? INT_MIN : nums2[cut2-1];
            r2=cut2==(size2) ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                if(n%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                return max(l1,l2)*1.0;
            }
            else{
                if(l1>r2){
                    high=cut1-1;
                }
                else{
                    low=cut1+1;
                }
            }
            
        }
        
        return 0.0;
}
