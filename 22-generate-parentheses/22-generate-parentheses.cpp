class Solution {
public:
    
    void helper(vector<string>& ans , int l , int r ,string st){
        
        if(l == 0 && r == 0)
        {
            ans.push_back(st);
            return;
        }
        
        if(l > 0){
            helper(ans , l-1 , r+1 , st+"(");
        }
        
        if(r > 0)
            helper(ans , l , r-1 , st+")");
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        helper(ans , n , 0 , "");
        
        return ans;
    }
};