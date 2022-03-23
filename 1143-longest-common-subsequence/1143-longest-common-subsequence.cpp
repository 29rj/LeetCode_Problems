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
        
        dp.resize(n+1,vector<int>(m+1, -1));
        
        return helper(s1,s2,n,m);
    }
};