class Solution {
public:
    
    bool hasAllCodes(string s, int k) {
        
        unordered_set<string>stk;
        int n =s.length();
        
        for(int i=0;i+k<=n;i++){
            stk.insert(s.substr(i,k));
        }
        
        return pow(2,k) == stk.size();
    }
};