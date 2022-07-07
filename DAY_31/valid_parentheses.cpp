bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> x;
    
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            x.push(s[i]);
        else{
            if(s[i]==')'){
                if(x.size()!=0 && x.top()=='(')
                    x.pop();
                else
                    return false;
            }
            else if(s[i]==']'){
                if(x.size()!=0 && x.top()=='[')
                    x.pop();
                else
                    return false;
            }
            else{
                if(x.size()!=0 && x.top()=='{')
                    x.pop();
                else
                    return false;
            }
        }
    }
    
    return x.size()==0;
}
