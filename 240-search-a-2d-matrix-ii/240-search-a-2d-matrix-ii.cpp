class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int n = matrix.size(),m=matrix[0].size();
        
        int r=n-1,c=0;
        
        while(r >=0 and c < m){
            if(matrix[r][c] == t){
                return true;
            }else if(matrix[r][c] < t){
                c++;
            }else
                r--;
        }
        
        return false;
    }
};