class Solution {
public:
    
    
    bool helper(string s1,string s2,string s3,int dp[101][101][201]){
        
        if(s1.length() == 0 && s2.length() == 0 && s3.length() == 0){
            return true;
        }
        
       if(s1.length() == 0 && s2.length() == 0 && s3.length() != 0){
            return false;
        }
        
        if(dp[s1.length()][s2.length()][s3.length()] != -1)
            return dp[s1.length()][s2.length()][s3.length()];
        
        bool b1=false,b2=false,b3=false;
        
        if(s1.length() > 0 && s1[0] == s3[0])
            b1 = helper(s1.substr(1),s2,s3.substr(1),dp);
        
        if(s2.length() > 0 && s2[0] == s3[0])
            b2 = helper(s1,s2.substr(1),s3.substr(1),dp);
        
        dp[s1.length()][s2.length()][s3.length()] = b1 || b2;
        
        return b1 || b2;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int dp[101][101][201];
        memset(dp,-1,sizeof(dp));
        return helper(s1,s2,s3,dp);
    }
};