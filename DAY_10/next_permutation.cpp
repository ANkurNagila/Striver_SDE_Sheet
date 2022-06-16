#include <bits/stdc++.h>

void reverse(vector<int>& nums,int i,int j){
    while(i<j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}

vector<int> nextPermutation(vector<int> &nums, int n)
{
    if(n<=1)
        return nums;
    
    int i=n-2;
    while(i>=0){
        if(nums[i]<nums[i+1])
            break;
        i--;
    }
    
    if(i>=0){
        int j=n-1;
        while(j>i){
            if(nums[j]>nums[i])
                break;
             j--;
        }
        swap(nums[i],nums[j]);
        reverse(nums,i+1,nums.size()-1);
    }
    else{
        reverse(nums,0,nums.size()-1);
    }   
    return nums;
}
