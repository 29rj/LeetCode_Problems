class Solution {
public:
    bool isPalindrome(string s){
        
        int i=0,j=s.length();
        j--;
        
        while(i<j){
            
            if(s[i++] != s[j--])
                return false;
        }
        
        return true;
    }
    
    void checkAll(vector<vector<string>> &ans, vector<string> &now,int st,string s){
        
        if(st == s.length()){
            ans.push_back(now);
            return;
        }
        
        for(int i=st;i<s.length();i++){
            
            if(isPalindrome(s.substr(st,i-st+1))){
                now.push_back(s.substr(st,i-st+1));
                checkAll(ans,now,i+1,s);
                now.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        
        vector<string>now;
        
        checkAll(ans,now,0,s);
        
        return ans;
        
    }
};