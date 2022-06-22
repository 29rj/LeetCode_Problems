class Solution {
public:
    
    vector<pair<int,int>>movements = {
        {0,1},{1,0},{-1,0},{0,-1}
    };
    
    bool isValid(int i,int j, int n ,int m){
        return i >= 0 && j >=0 && i < n && j < m;
    }
    
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0)),level(n,vector<int>(m,1e8));
        
        
        //multi-source bfs , apply to all 1's element
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    level[i][j]=0;
                    vis[i][j]=1;
                }
                
            }
        }
        
        int mx = -1;
        
        while(!q.empty()){
            
            auto par = q.front();
            int par_x = par.first;
            int par_y = par.second;
            q.pop();
            
            for(auto&move:movements){
                
                int child_x = move.first + par_x;
                int child_y = move.second + par_y;
                
                if(!isValid(child_x,child_y,n,m) || vis[child_x][child_y])
                    continue;
                
                q.push({child_x,child_y});
                level[child_x][child_y] = level[par_x][par_y]+1;
                vis[child_x][child_y] = 1;
                mx = max(mx,level[child_x][child_y]);
                
            } 
            
        }
        
        return mx;
        
        
    }
};