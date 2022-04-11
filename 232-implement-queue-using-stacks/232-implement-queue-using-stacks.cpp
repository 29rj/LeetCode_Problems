class MyQueue {
private:
    stack<int>stk;
public:
    stack<int> reverseStack(){
        stack<int>now;
        
        while(!stk.empty()){
            now.push(stk.top());
            stk.pop();
        }
        return now;
    }
    
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        stk = reverseStack();
        int tp = stk.top();
        stk.pop();
        stk = reverseStack();
        return tp;
    }
    
    int peek() {
        stk = reverseStack();
        int tp = stk.top();
        stk = reverseStack();
        return tp;
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */