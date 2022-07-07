void use(stack<int> &x,stack<int> &y){
    if(x.size()==0)
        return;
    
    if(y.size()==0){
        y.push(x.top());
        x.pop();
    }
    else{
        if(x.top()<y.top()){
            int ele=x.top(),ele2=y.top();
            x.pop();
            y.pop();
            x.push(ele2);
            x.push(ele);
        }
        else{
            y.push(x.top());
            x.pop();
        }
    }
    use(x,y);
}


void sortStack(stack<int> &x)
{
    stack<int> y;
    use(x,y);
    x=y;
    
}
