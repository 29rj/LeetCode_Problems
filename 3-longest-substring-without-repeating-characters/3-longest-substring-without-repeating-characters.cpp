class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.empty())
            return 0;
        
        map<char,int>stc;
        
        int mx = 1,i = 0,j = 0;
        
        while(j<s.length()){
            
            if(stc.find(s[j]) != stc.end()){
                // cout << stc[s[j]] << " " << j << "\n";
                i = max(i,stc[s[j]]+1);//2
                stc[s[j]] = j;//2
            }
            else {
                stc[s[j]] = j;
                // cout << s[j] << stc[s[j]] << " \n";
            }
            
            // cout << j << " " << i << "\n";
            mx = max(mx,j-i+1);
            
            j++;
        }
        
        return mx;
    }
};