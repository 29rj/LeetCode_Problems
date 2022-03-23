class Solution {
public:
    
    int helper(vector<int>& coins, int i,int amount,vector<vector<int>>&dp){
        
        if(i >= coins.size() || amount < 0)
            return INT_MAX;
        
        if(amount == 0){
            dp[i][amount] = 0;
            return 0;
        }
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int ans1 = INT_MAX , ans2 = INT_MAX;
        
        ans1 = helper(coins,i,amount-coins[i],dp);
        ans2 = helper(coins,i+1,amount,dp);
        
        if(ans1 < ans2){
            dp[i][amount] = ans1+1;
            return ans1+1;
        }
        else
        {
            dp[i][amount] = ans2;
            return ans2;
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        /*vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        
        int ans = helper(coins,0,amount,dp);
        
        if(ans == INT_MAX)
            return -1;
        
        return ans;*/
        
        int n = coins.size();
        
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
        
        for(int i=0;i<=coins.size();i++){
            
            for(int j=0;j<=amount;j++){
                
               if(i == 0)
                   dp[i][j] = INT_MAX;
               else if(j == 0)
                   dp[i][j] = 0;
               else{
                   
                   if(coins[i-1] <= j){
                       int mini = dp[i][j-coins[i-1]];
                       if(mini == INT_MAX)
                           dp[i][j] = min(dp[i-1][j],INT_MAX);
                       else
                           dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
                   }
                   else{
                       dp[i][j] = dp[i-1][j];
                   }
                   
               }
            }
        }
        
        
        if(dp[n][amount] == INT_MAX)
            return -1;
        return dp[n][amount];
    }
};