class Solution {
public:
    
    vector<char>chr={'a','e','i','o','u'};
    
    unordered_map<char,vector<char>>mp;
        
    
    const int M = 1e9+7;
    
    int helper(int &n,char ch,int len,vector<vector<int>>&dp){
        
        if(n == len){
            // cout << s << "\n";
            return 1;
        }
        
        int num = ch-'a';
        
        if( dp[len][num] != -1){
            return dp[len][num];
        }
        
        int sum = 0;
        
        for(int i=0;i<mp[ch].size();i++){
            
            sum = (sum + helper(n,mp[ch][i],len+1,dp))%M;
        }
        
        return dp[len][num] = sum;
    }
    
    int countVowelPermutation(int n) {
        
        // string s="";
        
        vector<vector<int>>dp(n+1,vector<int>(26,-1));
        
        mp['a'] = {'e'};
        mp['e'] = {'a','i'};
        mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
        
        int sum = 0;
        
        for(int i=0;i<chr.size();i++){
            
            sum = (sum + helper(n,chr[i],1,dp))%M;
        }
        
        return sum;
    }
};