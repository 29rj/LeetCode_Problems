class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char>st;
        
        int left = 0, right = 0, n = s.length(),mx = 0;
        
        while(left < n && right < n){
            
            if(st.find(s[right]) == st.end()){
                st.insert(s[right++]);
                mx = max(mx,right-left);
            }else{
                st.erase(s[left++]);
            }
        }
        
        return mx;
    }
};