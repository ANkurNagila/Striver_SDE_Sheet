string writeAsYouSpeak(int n) 
{
    if(n==0)
            return "";
        
    string s="";
    s="1";
    n--;
        
    while(n--){
            int count=1;
            string t="";
            char e=s[0];
            for(int i=1;s[i]!='\0';i++){
                if(s[i]==e){
                    count++;
                }
                else{
                    t=t+to_string(count)+e;
                    e=s[i];
                    count=1;
                }
            }
            
            t=t+to_string(count)+e;
            s=t;
    }
        
   return s;
}
