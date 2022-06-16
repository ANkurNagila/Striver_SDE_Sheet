vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
	vector<vector<long long int>> ans;
	if(n==0)
		return ans;
	
	vector<long long int> temp(1,1);
	ans.push_back(temp);
	
	for(int i=1;i<n;i++)
	{
		vector<long long int> x(i+1,1);
		for(int j=1;j<i;j++)
		{
			x[j]=ans[i-1][j-1]+ans[i-1][j];
		}
		ans.push_back(x);
	}
	
	return ans;
}
