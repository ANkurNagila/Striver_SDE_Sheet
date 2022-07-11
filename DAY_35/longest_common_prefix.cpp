string longestCommonPrefix(vector<string> &strs, int n)
{
        string ans=strs[0];
        
        for(int i=1;i<n;i++){
            string temp="";
            for(int j=0;j<strs[i].size() && j<ans.size();j++){
                if(ans[j]==strs[i][j])
                    temp+=ans[j];
                else
                    break;
            }
            
            if(temp.size()==0)
                return temp;
            
            ans=temp;
            
        }
        
        return ans;
      
}


