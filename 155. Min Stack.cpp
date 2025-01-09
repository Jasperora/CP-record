class MinStack {
private:
    stack<int> s;
    stack<int> min_prefix;
public:
    MinStack() {
    
    }
    
    void push(int val) {
        s.push(val);
        if(min_prefix.empty() || val<min_prefix.top())
            min_prefix.push(val);
        else
            min_prefix.push(min_prefix.top());
    }
    
    void pop() {
        s.pop();
        min_prefix.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_prefix.top();
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