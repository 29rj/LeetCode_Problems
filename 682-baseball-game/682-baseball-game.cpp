class Solution {
public:
    
    int calPoints(vector<string>& ops) {
        stack<int>stk;
        
        for(auto&it:ops){
        
            if(it == "C"){
                
                stk.pop();
                
            }
            else if(it == "D"){
                int n = stk.top();
                n *= 2;
                stk.push(n);
               
            }
            else if(it == "+"){
                int n1 = stk.top();
                stk.pop();
                int n2 = stk.top();
                stk.pop();
                
                stk.push(n2);
                stk.push(n1);
                stk.push(n1+n2);
                
            }
            else{
                int num = stoi(it);
                stk.push(num);
                
            }
        }
        
        int sum = 0;
        
        while(!stk.empty()){
            int n = stk.top();
            stk.pop();
            sum+=n;
        }
        
        return sum;
        
    }
};