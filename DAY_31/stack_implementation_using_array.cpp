class Stack {
private:
    vector<int> arr;
    int capa;
    
public:
    Stack(int capacity) {
        capa=capacity;
    }

    void push(int num) {
        this->arr.push_back(num);
    }

    int pop() {
        if(this->arr.size()==0)
            return -1;
        
        int ele=this->arr.back();
        arr.pop_back();
        return ele;
    }
    
    int top() {
        if(this->arr.size()==0)
            return -1;
        int ele=this->arr.back();
        return ele;
    }
    
    int isEmpty() {
        return this->arr.size()==0;
    }
    
    int isFull() {
        return this->arr.size()==this->capa;
        
    }
    
};
