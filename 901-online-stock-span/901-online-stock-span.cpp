class StockSpanner {
public:
    stack<pair<int,int>>stk;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int c = 1;
        
        if(!stk.empty() && stk.top().first > price){
            // stk.pop();
            stk.push({price,c});
        }
        else{
            
            while( !stk.empty() && stk.top().first <= price){
                c += stk.top().second;
                stk.pop();
            }
            
            stk.push({price,c});
        }
        
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */