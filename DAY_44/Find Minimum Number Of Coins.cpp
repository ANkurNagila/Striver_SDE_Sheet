int findMinimumCoins(int amount) 
{
    int coins[]={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ans=0;
    
    for(int i=8;i>=0;i--){
        int ele=amount/coins[i];
        if(ele!=0){
            ans+=ele;
            amount-=ele*coins[i];
        }
        
        if(amount==0)
            break;
    }
    
    return ans;
}
