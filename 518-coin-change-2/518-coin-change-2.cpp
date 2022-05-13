class Solution {
public:
    vector<vector<int>>dp;
    
    int helper(vector<int>& coins, int amount ,int i){ 
        
        if(amount == 0)
            return 1;
        
        if(i==coins.size())
            return 0;
        
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        
        int ans=0;
        
        if(coins[i]<=amount){
            
            if(dp[i][amount-coins[i]] != -1)
                ans += dp[i][amount-coins[i]];
            else
                ans += helper(coins,amount-coins[i],i);
            
            if(i+1< coins.size() && dp[i+1][amount] != -1)
                ans += dp[i+1][amount];
            else
                ans += helper(coins,amount,i+1);
        }else{
            ans = helper(coins,amount,i+1);
        }
        
        dp[i][amount] = ans;
        return ans;
    }
    
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        return helper(coins,amount,0);
    }
};