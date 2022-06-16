long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long int max=0;
    long long int ele=0;
    for(int i=0;i<n;i++)
    {
        ele+=arr[i];
        if(ele<arr[i])
            ele=arr[i];
        if(ele>max)
            max=ele;
     }
    
    return max;
        
}
