#include<queue>
class Kthlargest {
public:
    priority_queue<int,vector<int> ,greater<int>> x;
    int k;    
    Kthlargest(int k, vector<int> &arr) {
        this->k=k;
        
        for(int i=0;i<arr.size();i++){
            if(i<k)
                x.push(arr[i]);
            else{
                if(arr[i]<=x.top())
                    continue;
                else{
                    x.pop();
                    x.push(arr[i]);
                }
            }
        }
    }

    void add(int num) {
        // Write your code here.
        if(num<=x.top())
             return ;
        else{
              x.pop();
              x.push(num);
        }
    }

    int getKthLargest() {
       // Write your code here.
        return x.top();
    }

};
