class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size() , m = grid[0].size();
        
        // int mod = 2*(m+n) - 1;
        
        // k = k % mod;
        
        int prev = grid[n-1][m-1];
        
        for(int i=0;i<k;i++){
            
            prev = grid[n-1][m-1];
            
            for(int i=0;i<n;i++){
                
                for(int j=0;j<m;j++){
                    
                    int curr = grid[i][j];
                    grid[i][j] = prev;
                    prev = curr;
                }
            }
        }
        
        grid[0][0]=prev;
        
        return grid;
        
    }
};