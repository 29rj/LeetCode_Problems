// class Solution {
// public:
    
//     vector<vector<int>>dir;
    
//     int helper(vector<vector<int>>& matrix, vector<vector<int>>&dp , int x, int y) {
        
//         int m = matrix.size(), n = matrix[0].size();
        
//         dp[x][y]=1;
        
//         for(int i=0;i<4;i++) {
            
//             int nx = x + dir[i][0], ny = y + dir[i][1];
            
//             if(nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[x][y]<matrix[nx][ny]){
//                 if(dp[nx][ny] != -1){
//                     dp[]
//                 }
//             }
//         }
        
//     }
    
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
        
//         dir = {{-1,0},{0,-1},{0,1},{1,0}};
        
//         int m = matrix.size(), n = matrix[0].size();
        
//         vector<vector<int>>dp(m,vector<int>(n,-1));
        
//         dp[0][0] = 1;
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j] == -1){
//                     helper(matrix,dp,0,0,1);
//                 }
//             }
//         }
//     }
// };


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (!rows) return 0;
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        std::function<int(int, int)> dfs = [&] (int x, int y) {
            if (dp[x][y]) return dp[x][y];
            vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (auto &dir : dirs) {
                int xx = x + dir[0], yy = y + dir[1];
                if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
                if (matrix[xx][yy] <= matrix[x][y]) continue;
                dp[x][y] = std::max(dp[x][y], dfs(xx, yy));
            }
            return ++dp[x][y];
        };
        
        int ret = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ret = std::max(ret, dfs(i, j));
            }
        }
        
        return ret;
    }
};