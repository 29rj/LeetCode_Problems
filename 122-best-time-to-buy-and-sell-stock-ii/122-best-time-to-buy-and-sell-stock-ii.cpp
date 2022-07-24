class Solution {
public:
    vector<vector<int>>dp;
    
    int helper(vector<int>&prices,int i,bool buy){
        
        if(i == prices.size()){
            return 0;
        }
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy){
            return dp[i][buy] = max((-prices[i] + helper(prices,i+1,0)),helper(prices,i+1,1));
        }else{
            return dp[i][buy] = max(prices[i]+helper(prices,i+1,1),helper(prices,i+1,0));
        }
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        dp.resize(n,vector<int>(2,-1));

        return helper(prices,0,1);
        
    }
};