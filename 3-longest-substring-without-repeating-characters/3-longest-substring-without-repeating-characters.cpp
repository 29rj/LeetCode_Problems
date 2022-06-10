class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == ""){
            return 0;
        }
        unordered_map<char,int>mp;
        
        int left = 0,mx=1;
        
        for(int i=0;i<s.length();i++){
            
            if(mp.find(s[i]) != mp.end()){
                left = max(left,mp[s[i]]+1);
            }
            
            mx = max(mx,i-left+1);
            mp[s[i]] = i;
            
        }
        
        return mx;
    }
};