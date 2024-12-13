class MinStack {
public:
    stack<int> stk;
    stack<int> mini;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(mini.empty() or mini.top()>=val) {
            mini.push(val);
        }
    }
    
    void pop() {
        if(stk.top() == mini.top()) {
            mini.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */