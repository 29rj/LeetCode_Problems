class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        auto compare = [&](string &s1,string &s2){
            if(s1.size() != s2.size()+1)
                return false;
            
            int i=0,j=0;
            
            while(i<s1.size()){
                
                if(s1[i] == s2[j]){
                    i++,j++;
                }else{
                    i++;
                }
            }
            
            return s1.size() == i && s2.size() == j;
        };
        
        
        //LIS
        sort(words.begin(),words.end(),[&](string &w1,string &w2){
            return w1.length()<w2.length();
        });
            
        vector<int>dp(words.size(),1);
        
        int mx = 1;
        
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                }
            }
            
            mx = max(dp[i],mx);
        }
        
        
        return mx;
    }
};