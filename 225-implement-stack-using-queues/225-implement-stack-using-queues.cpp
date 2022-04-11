class MyStack {
private:
    queue<int>q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        vector<int>arr;
        while(!q.empty()){
            arr.push_back(q.front());
            q.pop();
        }
        
        int n = arr.size();
        
        for(int i=0;i<arr.size()-1;i++)
            q.push(arr[i]);
        
        return arr[n-1];
    }
    
    int top() {
        vector<int>arr;
        
        while(!q.empty()){
            arr.push_back(q.front());
            q.pop();
        }
        
        int n = arr.size();
        
        for(int i=0;i<arr.size();i++)
            q.push(arr[i]);
        
        return arr[n-1];
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */