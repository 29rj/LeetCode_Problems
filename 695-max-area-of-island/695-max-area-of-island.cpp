class Solution {
public:
    
    int dfs(vector<vector<int>>&grid,int r,int c,vector<vector<bool>>&vis){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0 || vis[r][c]){
            return 0;
        }
        
        vis[r][c] = true;
        
        int temp = dfs(grid,r+1,c,vis) + dfs(grid,r,c+1,vis) + dfs(grid,r-1,c,vis) + dfs(grid,r,c-1,vis) + 1;
        
        return temp;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int mx = 0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(!vis[i][j] && grid[i][j] == 1){
                    mx = max(1,mx);
                    mx = max(mx,dfs(grid,i,j,vis));
                }
            }
        }
        
        return mx;
    }
};