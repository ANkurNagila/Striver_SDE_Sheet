int uniqueElement(vector<int> arr, int n)
{
    int ele=0;
    for(int i=0;i<n;i++)
        ele=ele^arr[i];
    
    return ele;
}
