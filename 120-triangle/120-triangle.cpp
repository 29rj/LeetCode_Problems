class Solution {
public:
    
    int helper(vector<vector<int>>&t,int r,int c,vector<vector<int>>&dp){
        
        if(r == t.size())
            return 0;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int ans1 = helper(t,r+1,c,dp);
        int ans2 = helper(t,r+1,c+1,dp);
        
        int ans = min(ans1,ans2) + t[r][c];
        
        dp[r][c] = ans;
        
        return ans;
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        int sz = t.size();
        int lz = t[sz-1].size();
        
        vector<vector<int>>dp(sz,vector<int>(lz,-1));
        return helper(t,0,0,dp);
    }
};