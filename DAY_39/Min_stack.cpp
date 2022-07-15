// Implement class for minStack.
class minStack
{
 	public:
        vector<int> arr;
        stack<int> x;
		
		// Constructor
		minStack() 
		{ 
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			this->x.push(num);
            if(this->arr.size()<1)
                this->arr.push_back(num);
            else{
                this->arr.push_back(min(num,this->arr.back()));
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            int ele=-1;
            if(this->x.size()!=0){
                ele=this->x.top();
                this->x.pop();
                this->arr.pop_back();
            }
            return ele;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
            if(this->x.size()!=0)
                return this->x.top();
            return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(this->arr.size()!=0)
                return this->arr.back();
            return -1;
		}
};
