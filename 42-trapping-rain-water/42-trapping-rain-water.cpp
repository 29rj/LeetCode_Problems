class Solution {
public:
    int trap(vector<int>& h) {
        
        int left[h.size()],right[h.size()];
        
        int n = h.size();
        
        left[0] = h[0] , right[n-1] = h[n-1];
        
        for(int i=1;i<h.size();i++){
            left[i] = max(left[i-1],h[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],h[i]);
        }
        
        int sum = 0;
        
        for(int i=1;i<n-1;i++){
            if(h[i] <= left[i-1] && h[i]<= right[i+1]){
                sum += min(left[i-1],right[i+1]) - h[i];
            }
        }
        
        return sum;
    }
};