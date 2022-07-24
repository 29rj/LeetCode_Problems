class Solution {
public:
    vector<vector<vector<int>>>dp;
    
    int helper(vector<int>&prices,int k,int i,bool buy){
        
        if(i == prices.size() || k == 0){
            return 0;
        }
        
        if(dp[i][k][buy] != -1)
            return dp[i][k][buy];
        
        if(buy){
            return dp[i][k][buy] = max(-prices[i]+helper(prices,k,i+1,0),helper(prices,k,i+1,1));
        }else{
            return dp[i][k][buy] = max(prices[i]+helper(prices,k-1,i+1,1),helper(prices,k,i+1,0));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(prices,k,0,1);
    }
};