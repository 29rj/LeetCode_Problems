class Solution {
public:
    
    bool isAlright(vector<vector<char>>& board,int r,int c, char ch){
        
        for(int k=0;k<9;k++){
            
            if(board[k][c] == ch)
                return false;
            
            if(board[r][k] == ch)
                return false;
            
            if(board[3*(r/3)+k/3][3*(c/3)+k%3] == ch)
                return false;
        }
        
        return true;
    }
    
    bool helper(vector<vector<char>>& board){
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j] == '.') {
                    
                    for(char ch = '1'; ch <= '9'; ch++){
                        
                        if(isAlright(board,i,j,ch)){
                            
                            board[i][j] = ch;
                            
                            if(helper(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        helper(board);
        
        for(auto&it:board){
            for(auto&ch:it){
                cout << ch << " ";
            }
            cout << "\n";
        }
        
    }
};