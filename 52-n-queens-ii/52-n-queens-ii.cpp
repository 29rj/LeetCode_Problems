class Solution {
public:
    int totalNQueens(int n) {
        
        vector<vector<string>>ans;
        string s="";
        
        for(int i=0;i<n;i++){
            s +=".";
        }
        
        vector<string>now(n,s);
        
        auto isAlright = [&](vector<string>&now,int row,int col){
            
            int cr=row,cc=col;
            while(cr>=0 && cc >=0){
                if(now[cr][cc] == 'Q'){
                    return false;
                }
                cr--,cc--;
            }
            
            cr=row,cc=col;
            while(cr>=0 && cc < now.size()){
                if(now[cr][cc] == 'Q'){
                    return false;
                }
                cr--,cc++;
            }
            
            cr=row,cc=col;
            while(cr>=0){
                if(now[cr][col] == 'Q'){
                    return false;
                }
                cr--;
            }
            
            return true;
        };
        
        function<void(vector<vector<string>>&,vector<string>&,int)> helper = [&](vector<vector<string>>&ans,vector<string>&now,int row){
            
            if(row == now.size()) {
                ans.push_back(now);
                return;
            }
            
            for(int j=0;j<now.size();j++) {
                
                if(isAlright(now,row,j)) {
                    now[row][j] = 'Q';
                    helper(ans,now,row+1);
                    now[row][j] = '.';
                }
            } 
        };
        
        helper(ans,now,0);
        
        return ans.size();
    }
};