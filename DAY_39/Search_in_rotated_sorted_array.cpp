int search(int* arr, int n, int key) {
    // Write your code here.
    int x;
    int first=0,last=n-1;
    while(first<last){
        int mid=(first+last)/2;
        
        if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
        {
            x=mid;
            break;
        }
        else
        {
            if(arr[mid]<arr[last])
                last=mid-1;
            else
                first=mid+1;
        }
    }
    if(first==last)
        x=first;
    
    if(key<=arr[n-1] && key>=arr[x]){
        first=x;
        last=n-1;
    }
    else{
        first=0;
        last=x-1;
    }
    
    while(first<=last){
        int mid=(first+last)/2;
        if(arr[mid]>key)
            last=mid-1;
        else if(arr[mid]<key)
            first=mid+1;
        else
            return mid; 
    }
    return -1;
}
