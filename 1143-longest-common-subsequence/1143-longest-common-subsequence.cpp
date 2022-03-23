class Solution {
public:
    vector<vector<int>>dp;
    
    int helper(string &s1, string &s2,int n, int m) {
        
        if(n == 0 || m == 0 ){
            return 0;
        }
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        
        if(s1[n-1] == s2[m-1]){
            dp[n][m] = 1+helper(s1,s2,n-1,m-1);
            return dp[n][m];
        }
        else{
            dp[n][m] = max( helper(s1,s2,n,m-1) , helper(s1,s2,n-1,m) );
            return dp[n][m];
        }
    }

    int longestCommonSubsequence(string s1, string s2) {
        
        int n = s1.length() , m = s2.length();
        
//         dp.resize(n+1,vector<int>(m+1, -1));
//         return helper(s1,s2,n,m);
        
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(s1[i-1] == s2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        return dp[n][m];
        
    }
};