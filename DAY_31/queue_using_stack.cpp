#include<bits/stdc++.h>
class Queue {
    public:
    stack<int> x;
    Queue() {
    }

    void enQueue(int val) {
        stack<int> y;
        while(x.size()!=0){
            y.push(x.top());
            x.pop();
        }
        
        x.push(val);
        while(y.size()!=0){
            x.push(y.top());
            y.pop();
        }
    }

    int deQueue() {
        if(x.size()==0)
            return -1;
        int ele=x.top();
        x.pop();
        return ele;
    }

    int peek() {
        if(x.size()==0)
            return -1;
        return x.top();
    }

    bool isEmpty() {
        return x.size()==0;
    }
};




/***********************************Alternative way (O(1) push and O(1) pop) *********************************************/

#include<bits/stdc++.h>
class Queue {
    public:
    stack<int> x,y;
    Queue() {
    }

    void enQueue(int val) {
        x.push(val);
    }

    int deQueue() {
        if(y.size()==0 && x.size()==0)
            return -1;
        
        if(y.size()==0){
            while(x.size()!=0){
                y.push(x.top());
                x.pop();
            }
        }
        
        int ele=y.top();
        y.pop();
        return ele;
            
    }

    int peek() {
        if(y.size()==0 && x.size()==0)
            return -1;
        
        if(y.size()==0){
            while(x.size()!=0){
                y.push(x.top());
                x.pop();
            }
        }
        
        int ele=y.top();
        return ele;
    }

    bool isEmpty() {
        return (x.size()==0 && y.size()==0);
    }
};
