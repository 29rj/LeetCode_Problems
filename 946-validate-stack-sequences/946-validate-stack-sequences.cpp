class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int>stk;
        int n = pushed.size();
        int i=0,j=0;
        
        while(i<n || j<n){
            
            if(j < n && !stk.empty() && stk.top() == popped[j]){
                stk.pop();
                j++;
            }
            
            else if(i < n) {
                stk.push(pushed[i]);
                i++;
            }
            else
                break;
        }
        
        
        return (i == n && j == n);
    }
};