class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        
        for(int i=0;i<=coins.size();i++) {
            
            for(int j=0;j<=amount;j++) {
                
                if(i==0){
                    dp[i][j] = INT_MAX;
                }else if(j==0){
                    dp[i][j] = 0;
                }else{
                   if(coins[i-1]<=j){
                        int mn = dp[i][j-coins[i-1]];
                        if(mn == INT_MAX){
                            dp[i][j] = min(dp[i-1][j],INT_MAX);
                        }else{
                            dp[i][j] = min(dp[i-1][j],mn+1);
                        }
                   }else{
                       dp[i][j] = dp[i-1][j];
                   }
                }
            }
        }
        
        if(dp[coins.size()][amount] == INT_MAX)
            return -1;
        
        return dp[coins.size()][amount];
    }
};