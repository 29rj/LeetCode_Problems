class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int n = matrix.size(),m=matrix[0].size();
        
        int r=0,c=m-1;
        
        while(r < n and c >=0){
            if(matrix[r][c] == t){
                return true;
            }else if(matrix[r][c] < t){
                r++;
            }else
                c--;
        }
        
        return false;
    }
};