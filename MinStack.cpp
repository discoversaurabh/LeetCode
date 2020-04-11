/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
class MinStack {

    /** initialize your data structure here. */
    vector<int> min;
    vector<int> stack;
    public:
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if(min.empty()||min.back()>=x) // very important condition : "min.empty()" => generally gets missed
            min.push_back(x);
    }
    
    void pop() {
        if(stack.back()==min.back())
            min.pop_back();
        
        stack.pop_back();
    }
    
    int top() {
        if(!stack.empty())
        return stack.back();
        
        return -1;
    }
    
    int getMin() {
        if(!min.empty())
        return min.back();
        
        return -1;
    }
};
