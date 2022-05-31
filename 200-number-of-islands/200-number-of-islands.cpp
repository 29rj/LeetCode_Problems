class Solution {
public:
    
    void dfs(vector<vector<char>>&grid,int i,int j){
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ){
            return;
        }
        
        grid[i][j]='0';
        
        //top
        if(i-1>=0 && grid[i-1][j]=='1'){
            dfs(grid,i-1,j);
        }
        
        //left
        if(j-1>=0 && grid[i][j-1]=='1'){
            dfs(grid,i,j-1);
        }
        
        //down
         if(i+1<grid.size() && grid[i+1][j]=='1'){
            dfs(grid,i+1,j);
        }
        
        //right
         if(j+1 < grid[0].size() && grid[i][j+1]=='1'){
            dfs(grid,i,j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<char>>vis(grid.size(),vector<char>(grid[0].size(),false));
        int cn = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    cn++;
                }
            }
        }
        
        return cn;
    }
};