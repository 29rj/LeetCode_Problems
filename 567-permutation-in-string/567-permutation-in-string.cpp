class Solution {
public:
    bool isEqual(vector<int>&f1,vector<int>&f2){
        
        for(int i=0;i<26;i++){
            if(f1[i]!=f2[i])
                return false;
        }
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int>f1(26,0),f2(26,0);
        
        for(int i=0;i<s1.length();i++){
            f1[s1[i]-'a']++;
        }
        
        int left = 0;
        
        for(int i=0;i<s2.length();i++){
            
            f2[s2[i]-'a']++;
            
            if(f1 == f2)
                return true;
            
            if(i-left+1 >= s1.length()) {
                f2[s2[left]-'a']--;
                left++;
            }
        }
        return false;
    }
};