class MinStack {
public:
    stack<int>stk;
    
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        if(!stk.empty())
            stk.pop();
    }
    
    int top() {
        if(!stk.empty())
            return stk.top();
        return -1;
    }
    
    int getMin() {
        vector<int>ans;
        int mn = INT_MAX;
        
        while(!stk.empty()){
            ans.push_back(stk.top());
            mn = min(mn,stk.top());
            stk.pop();
        }
        
        int k = ans.size();
        k--;
        
        for(int i=k;i>=0;i--){
            stk.push(ans[i]);
        }
        
        return mn;
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