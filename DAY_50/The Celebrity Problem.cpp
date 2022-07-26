/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<stack>
int findCelebrity(int n) {
    stack<int> x;
    
    for(int i=0;i<n;i++)
        x.push(i);
    int count=0;
    while(x.size()>1){
        int ele=x.top();
        x.pop();
        int ele2=x.top();
        x.pop();
        
        if(knows(ele,ele2) && !knows(ele2,ele))
            x.push(ele2);
        else if(!knows(ele,ele2) && knows(ele2,ele))
            x.push(ele);
        
    }
    
    
    if(x.size()==0)
        return -1;
    
    for(int i=0;i<n;i++){
        if((i!=x.top() && !knows(x.top(),i) && knows(i,x.top()))||i==x.top())
            continue;
        else
            return -1;
    }
    
    return x.top();
}
