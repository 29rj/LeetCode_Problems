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
        
        int ans;
        
        if(coins[i]<=amount){
            ans = helper(coins,amount-coins[i],i) + helper(coins,amount,i+1);
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