class Solution {
public:
    bool isAlright(vector<string>&now,int col,int row) {
        
        int dr = row,dc = col,n = now.size();
        
        while(row >= 0 && col >=0){
            
            if(now[row][col] == 'Q')
                return false;
            row--,col--;
        }
        
        row = dr,col = dc;
        
        while(row < n && col >= 0){
            
            if(now[row][col] == 'Q')
                return false;
            row++,col--;
        }
        
        row = dr,col = dc;
        
        while(col >= 0){
            
            if(now[row][col] == 'Q')
                return false;
            col--;
        }
        
        return true;
        
    }
    
    void helper(vector<vector<string>> &ans, vector<string>& now,int col){
        
        if(col == now.size()){
            ans.push_back(now);
            return;
        }
        
        for(int i=0;i<now.size();i++){
            
            if(isAlright(now,col,i)){
                now[i][col]='Q';
                helper(ans,now,col+1);
                now[i][col]='.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        
        string st="";
        
        for(int i=0;i<n;i++){
            st+=".";
        }
        
        vector<string>now(n,st);
        
        // for(auto&it:now){
        //     cout << it << "\n";
        // }
        
        helper(ans,now,0);
        
        return ans;
    }
};