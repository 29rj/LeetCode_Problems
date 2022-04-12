class Solution {
public:
    
    pair<int,int> giveCount(vector<vector<int>>&board,int i,int j){
        
        int lv = 0,de = 0;
        
        int n = board.size(), m = board[0].size();
        
        if(i-1>=0 && j-1>=0) {
            if(board[i-1][j-1] == 0) de++;
            else lv++;
            
            // if(i == 1 && j == 2)
            //     cout << "1" << "\n";
        }
        
        if(i-1 >=0 && j+1<m){
            if(board[i-1][j+1] == 0) de++;
            else lv++;
            
//             if(i == 1 && j == 2)
//                 cout << "2" << "\n";
        }
        
        if(i+1<n && j-1>=0){
            if(board[i+1][j-1] == 0) de++;
            else lv++;
            
            // if(i == 1 && j == 2)
            //     cout << "3" << "\n";
        }
        
        if(i+1<n && j+1<m){
            if(board[i+1][j+1] == 0) de++;
            else lv++;
            
            // if(i == 1 && j == 2)
            //     cout << "4" << "\n";
        }
        
        if(i-1>=0){
            if(board[i-1][j] == 0) de++;
            else lv++;
            
//             if(i == 1 && j == 2)
//                 cout << "5" << "\n";
        }
        
        if(i+1<n){
            if(board[i+1][j] == 0) de++;
            else lv++;
            
            // if(i == 1 && j == 2)
            //     cout << "6" << "\n";
        }
        
        
        if(j-1>=0){
            if(board[i][j-1] == 0) de++;
            else lv++;
            
//             if(i == 1 && j == 2)
//                 cout << "7" << "\n";
        }
        
        if(j+1<m){
            if(board[i][j+1] == 0) de++;
            else lv++;
            
            // if(i == 1 && j == 2)
            //     cout << "8" << "\n";
        }
        
        pair<int,int>pr = {lv,de};
        
        return pr;
        
            
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>>ans(board.size(),vector<int>(board[0].size()));
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                pair<int,int>pr = giveCount(board,i,j);
                
                if(board[i][j] == 0 && pr.first == 3)
                    ans[i][j] = 1;
                else if(board[i][j] == 1 && pr.first < 2)
                    ans[i][j] = 0;
                else if(board[i][j] == 1 && pr.first > 3)
                    ans[i][j] = 0;
                else
                    ans[i][j] = board[i][j];
                
                if(i == 1 && j == 2)
                    cout << pr.first << " " << pr.second << "\n"; 
            }
        }
        
        board = ans;
        
    }
};