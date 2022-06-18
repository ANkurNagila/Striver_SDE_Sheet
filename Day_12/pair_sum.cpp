#include<unordered_map>

bool sortcol( const vector<int>& v1,const vector<int>& v2 ) {
 	return v1[0] < v2[0];
}

vector<vector<int>> pairSum(vector<int> &arr, int s){
   
    vector<vector <int>> res;
    unordered_map<int,int> set;
    
    for(int i=0;i<arr.size();i++)
    {
        int ele=s-arr[i];
        
        if(set.find(ele)!=set.end())
        {
            vector<int> temp;
            auto it=set.find(ele);
            while(it!=set.end() and it->first==ele)
            {
                int j=0;
                while(j<it->second)
                {
                    //cout<<ele<<" "<<arr[i]<<endl;
                    if(ele<arr[i])
                    {
                        temp.push_back(ele);
            			temp.push_back(arr[i]);                        
                    }
                    else
                    {
                        temp.push_back(arr[i]);
            			temp.push_back(ele);                        
                    }
                    res.push_back(temp);
                    j++;
                }
                it++;
            }
            
        }
        
        
        if(not(set.find(arr[i])!=set.end()))
            set.insert(make_pair(arr[i],1));
        else
        {
            auto it=set.find(arr[i]);
            while(it!=set.end() and it->first==arr[i])
            {
                it->second++;
                it++;
            }
        }
    }
    sort(res.begin(), res.end(),sortcol);
    return res;

}
