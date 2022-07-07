#include<bits/stdc++.h>
class Stack {
    private:
        queue<int> x;
   public:
    Stack() {
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return this->x.size();
    }

    bool isEmpty() {
        return this->x.size()==0;
    }

    void push(int element) {
        x.push(element);
    }

    int pop() {
        if(this->x.size()==0)
            return -1;
        
        int ele;
        int size=this->x.size()-1;
        
        while(size--){
            ele=this->x.front();
            this->x.pop();
            this->x.push(ele);
        }
        
        ele=this->x.front();
        this->x.pop();
        
        return ele;
    }

    int top() {
        if(this->x.size()==0)
            return -1;
        
        int ele;
        int size=this->x.size()-1;
        
        while(size--){
            ele=this->x.front();
            this->x.pop();
            this->x.push(ele);
        }
        
        ele=this->x.front();
        this->x.pop();
        this->x.push(ele);
        
        return ele;
    }
};
