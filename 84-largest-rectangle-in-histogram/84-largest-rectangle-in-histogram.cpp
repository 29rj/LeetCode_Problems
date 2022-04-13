class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int>left(n),right(n);
        
        stack<int>stk;
        stk.push(0);
        
        left[0] = 0;
        
        for(int i=1;i<n;i++){
            
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            
            if(stk.empty())
                left[i] = 0;
            else
                left[i] = stk.top()+1;
            
            stk.push(i);
        }
        
        // for(auto&it:left)
        //     cout << it << " ";
        // cout << "\n";
        
        right[n-1] = n-1;
        
        stack<int>su;
        stk = su;
        // cout << stk.size() << "\n";
        stk.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            
            if(stk.empty()){
                right[i] = n-1;
            }
            else{
                right[i] = stk.top()-1;
            }
            
            stk.push(i);
        }
        
        // for(auto&it:right)
        //     cout << it << " ";
        // cout << "\n";
        
        int mx = 0;
        
        for(int i=0;i<n;i++){
            mx = max(mx,(right[i]-left[i]+1)*heights[i]);
        }
        
        return mx;
    }
};