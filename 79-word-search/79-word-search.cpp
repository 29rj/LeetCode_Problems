class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        function<bool(vector<vector<char>>&,int,int,int&,int&,string&)> helper = [&](vector<vector<char>>&board,int x,int y,int&m,int&n,string &st){
            
            if(st.size() == 0)
                return true;
            
            if(x >= m || y >= n || x < 0 || y < 0 || board[x][y] != st[0]){
                return false;
            }
            
            string str = st.substr(1);
            
            char c = board[x][y];
            
            board[x][y]='&';
            
            bool ans =  helper(board,x+1,y,m,n,str) || helper(board,x-1,y,m,n,str) || helper(board,x,y+1,m,n,str) || helper(board,x,y-1,m,n,str);
            
            board[x][y]=c;
            
            return ans;
        };
        
        int m = board.size(),n = board[0].size();
      
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(helper(board,i,j,m,n,word))
                    return true;
            }
        }
        
        return false;
    }
};