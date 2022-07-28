class Solution {
public:
    bool isAnagram(string s, string t) {
        
        multiset<char>st1,st2;
        
        for(int i=0;i<s.length();i++){
           st1.insert(s[i]);
        }
        
        for(int i=0;i<t.length();i++){
            st2.insert(t[i]);
        }
        
        return st1==st2;
    }
};