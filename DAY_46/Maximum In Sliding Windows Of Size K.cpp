#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> x;
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<k;i++){
        if(x.size()==0){
            x.push_back(i);
        }
        else{
            while(x.size()!=0 && nums[x.back()]<nums[i])
                x.pop_back();
            x.push_back(i);
        }
    }
    ans.push_back(nums[x.front()]);
    
    for(int i=k,j=0;i<n;i++,j++){
        if(x.size()!=0 && x.front()==j)
            x.pop_front();
        while(x.size()!=0 && nums[x.back()]<nums[i])
                x.pop_back();
            x.push_back(i);
        
        ans.push_back(nums[x.front()]);
    }
    
    return ans;
    
}
