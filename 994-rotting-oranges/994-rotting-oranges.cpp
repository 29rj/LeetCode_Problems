class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(),m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        queue<pair<int,int>> q;
        
        int c = 0,ch=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j] == 2){
                    q.push({i,j});
                    c=0;
                    ch=1;
                }
                
                if(grid[i][j] == 1){
                    c=-1;
                }
            }
        }
        
        if(ch == 1)
            c=0;
        
        while(!q.empty() && c!=-1){
            
            int k = q.size();
            
            while(k--){
                
                pair<int,int>pr = q.front();
                q.pop();
          
            int ci = pr.first ,cj = pr.second;
            
            if(ci-1>=0 && !vis[ci-1][cj] && grid[ci-1][cj] == 1 && grid[ci][cj] == 2){
                q.push({ci-1,cj});
                grid[ci-1][cj] = 2;
                vis[ci-1][cj] = true;
               
            }
            
            if(ci+1<n && !vis[ci+1][cj] && grid[ci+1][cj] == 1 && grid[ci][cj] == 2){
                q.push({ci+1,cj});
                grid[ci+1][cj] = 2;
                vis[ci+1][cj] = true;
            }
            
            if(cj+1<m  && !vis[ci][cj+1] && grid[ci][cj+1] == 1 && grid[ci][cj] == 2){
                q.push({ci,cj+1});
                grid[ci][cj+1] = 2;
                vis[ci][cj+1] = true;
            }
            
            if(cj-1>=0  && !vis[ci][cj-1] && grid[ci][cj-1] == 1 && grid[ci][cj] == 2){
                q.push({ci,cj-1});
                grid[ci][cj-1] = 2;
                vis[ci][cj-1] = true;
                
            }
                
            }
            
            if(q.empty())
                break;
            c++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    cout << c << "\n";
                    return -1;
                }
            }
        }
    
        return c;
    }
};