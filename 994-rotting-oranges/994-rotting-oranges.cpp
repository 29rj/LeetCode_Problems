class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        
        int m = grid.size(),n= grid[0].size();
        bool ch = false;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 2){
                    grid[i][j] = 0;
                    q.push({i,j});
                    ch = true;
                }
            }
        }
        
        int dir[][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        int depth = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz > 0) {
            
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int sr = r + dir[i][0];
                    int sc = c + dir[i][1];
                    
                    if(sr < 0 || sc < 0 || sr >= m || sc >= n || grid[sr][sc] == 0){
                        continue;
                    }
                    
                    q.push({sr,sc});
                    
                    grid[sr][sc] = 0;
                    
                }
                
                sz--;
            }
            
            depth++;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }

            }
        }
        
        return ch?depth-1:0;
    }
};