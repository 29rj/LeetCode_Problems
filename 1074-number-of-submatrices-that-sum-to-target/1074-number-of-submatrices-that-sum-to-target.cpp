class Solution {
public:
    vector<int> prefix;
    
//     vector<int> func(int r1,int r2,vector<vector<int>> &grid){
//         int n = grid.size(),m = grid[0].size();
//         vector<int> res(m);
        
//         for(int i = r1 ; i <= r2 ; i++){
//             for(int j = 0; j < m ; j++)
//                 res[j] += grid[i][j]; 
//         }
        
//         return res;
//     }
    
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
//         int n = mt.size(),m = mt[0].size();
//         prefix.assign(m,vector<int>());
//         int ans = 0 ;
        
//         for(in)
//         for(int i = 0 ; i < n ; i++){
//             for(int j = i ; j < n ; j++){
//                 vector<int> res = func(i,j,mt);
//                 map<int,int> m;
//                 m[0]++;
                
//             }
//         }
        
          int rows = matrix.size() , cols = matrix[0].size();
        
        if(rows < 1){
            return 0;
        }
        
        // calculate prefix sum for rows
        for(int row = 0 ; row < rows ; row++){
            for(int col = 1 ; col < cols ;col++){
                matrix[row][col] =  matrix[row][col] + matrix[row][col -1];
            }
        }
      
        int count = 0 , sum ;
        unordered_map<int , int> counter;
        for(int colstart = 0 ; colstart < cols ;colstart++){
            for(int col = colstart ; col < cols; col++){
                counter.clear();
                counter[0] = 1;
                sum =0;
                for(int row = 0 ; row < rows ;row++){
                    sum += matrix[row][col] - (colstart > 0 ? matrix[row][colstart - 1] : 0 );
                    count += (counter.find(sum- target) != counter.end() ? counter[sum-target] : 0);
                    counter[sum]++;
                }
            }
        }
        return count;
    }
};