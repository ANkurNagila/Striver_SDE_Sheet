int atoi(string str) {
    if(str.size()==0)
        return 0;
    
    int ans=0;
    int flag=1,f=0;
    
    if(str[0]==45){
         flag=-1;
         f=1;
    }
             
    for(int i=f;str[i]!='\0';i++){
        if(str[i]>=48 && str[i]<=57)
            ans=ans*10+(str[i]-48);
    }
    
    return flag*ans;
}
