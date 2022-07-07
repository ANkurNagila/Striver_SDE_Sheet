#include<bits/stdc++.h>
class Queue {
public:
    vector<int> ans;
    Queue() {
        // Implement the Constructor   
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return ans.size()==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        ans.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(ans.size()==0)
            return -1;
        
        int e=ans[0];
        for(int i=1;i<ans.size();i++)
            ans[i-1]=ans[i];
        ans.pop_back();
        return e;
    }

    int front() {
        // Implement the front() function
        if(ans.size()==0)
            return -1;        
        return ans[0];
    }
};
