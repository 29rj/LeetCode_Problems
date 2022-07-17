class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(),n = mat[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int dir[][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        
        while(!q.empty()){
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int r = sr + dir[i][0];
                int c = sc + dir[i][1];
                
                if(r < 0 || c < 0 || r >= m || c >= n || ans[r][c] != -1)
                    continue;
                
//                 if(r >=0 && c >=0 && r <= m && c <= n && ans[r][c] == -1){
                    // ans[r][c] = ans[sr][sc] + 1;
                    // q.push({r,c});
//                 }
                
                ans[r][c] = ans[sr][sc] + 1;
                q.push({r,c});
            }
        }
        
        return ans;
    }
};