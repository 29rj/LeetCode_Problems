class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.empty())
            return 0;
        
        unordered_map<char,int>stc;
        
        int mx = 1,i = 0,j = 0;
        
        while(j<s.length()){
            
            if(stc.find(s[j]) != stc.end()){
                i = max(i,stc[s[j]]+1);
                stc[s[j]] = j;
            }
            else {
                stc[s[j]] = j;
                
            }
            
            mx = max(mx,j-i+1);
            j++;
        }
        
        return mx;
    }
};