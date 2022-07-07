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
