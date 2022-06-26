class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        
        for(int i=1; i < cp.size(); i++){
            cp[i] += cp[i-1];
        }
        
        int n = cp.size();
        
        int maxi = INT_MIN;
        
        for(int i=0; i <= k ;i++){
            
            int left = INT_MIN , right = INT_MIN;
            
            if(i-1>=0){
                left = cp[i-1];
                
                right = (cp[n-1] - cp[n-(k-i)-1]);
                
                // cout << left << " " <<right << " " << n-(k-i)-1 << " " << (right + left) << "\n";
            }
            else{
                
                if(n-k-1>=0)
                    right = cp[n-1]-cp[n-k-1];
                else
                    right = cp[n-1];
            }
            
            // cout << left << " " << right << "\n";
            
            if(left == INT_MIN)
                left = 0;
            if(right == INT_MIN)
                right = 0;
            
            maxi = max(right+left,maxi);
        }
        
        return maxi;
    }
};