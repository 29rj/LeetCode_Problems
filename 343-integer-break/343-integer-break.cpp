class Solution {
public:
    
    int helper(int n){
        if(n==1)
            return 1;
        
        int mx = INT_MIN;
        
        for(int i=1;i<n; i++){
            
            int ans = helper(n-i)*i;
            
            mx = max(ans,mx);
        }
        
        return mx;
    }
    
    int integerBreak(int n) {
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i=3;i<=n;i++){
            int mx = 1;
            
            for(int j=1;j<=i-1;j++){
                
                mx = max(j*(i-j),mx);
                
                mx = max(dp[j]*(i-j),mx);
                
                mx = max(j*dp[i-j],mx);
                
                mx = max(dp[j]*dp[i-j],mx);
            }
            
            dp[i] = mx;
        }
        
        return dp[n];
    }
};