class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        vector<vector<int>>dir = {{1,0},{0,1},{0,-1},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
        
        queue<vector<int>>q;
        
        if(grid[0][0])
            return -1;
        
        q.push({0,0,1});
        
        int n = grid.size(), m = grid[0].size();
        
        grid[0][0] = 1;
        
        while(!q.empty()) {
            
            int sz = q.size();
            
            while(sz--) {
                
                vector<int>point = q.front();
                
                q.pop();
                
                if(point[0] == n-1 && point[1] == m-1){
                    return point[2];
                }
                    
                
                for(auto&it:dir) { 
                    
                    int nx = it[0] + point[0];
                    int ny = it[1] + point[1];
                    
                    
                    if(nx>=0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == 0) {
                        
                        grid[nx][ny] = 1;
                        q.push({nx,ny,point[2]+1});
                    }
                }
            }
        }
        
        return -1;
    }
};