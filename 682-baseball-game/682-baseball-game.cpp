class Solution {
public:
    
    void print (stack<int>stk){
        
        while(!stk.empty()){
            cout << stk.top() << " ";
            stk.pop();
        }
        
        cout << "\n";
    }
    
    
    int calPoints(vector<string>& ops) {
        stack<int>stk;
        
        for(auto&it:ops){
        
            if(it == "C"){
                // int ch = stk.top();
                stk.pop();
                print(stk);
            }
            else if(it == "D"){
                int n = stk.top();
                n *= 2;
                stk.push(n);
                // cout << n << " ";
                // print(stk);
            }
            else if(it == "+"){
                int n1 = stk.top();
                stk.pop();
                int n2 = stk.top();
                stk.pop();
                
                stk.push(n2);
                stk.push(n1);
                stk.push(n1+n2);
                // print(stk);
                
                // cout << n1 << " " << n2 << " "<< n1+n2 << " ";
            }
            else{
                int num = stoi(it);
                stk.push(num);
                // cout << num << " ";
                // print(stk);
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