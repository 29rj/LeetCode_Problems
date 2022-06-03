class NumMatrix {
public:
    vector<vector<int>>matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        
        this->matrix = matrix;
        
        for(int i=0 ; i < this->matrix.size(); i++){
            
            for(int j=0; j < this->matrix[0].size(); j++){
                
                if(i-1 >= 0 && j-1 >= 0)
                    this->matrix[i][j] -= this->matrix[i-1][j-1];
                if(i-1 >=0 )
                    this->matrix[i][j] += this->matrix[i-1][j];
                if(j-1 >= 0)
                    this->matrix[i][j] += this->matrix[i][j-1];
                
                // cout << this->matrix[i][j] << " "; 
            }
            
            // cout << "\n";
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        // cout << matrix[row2][col2] << " ";
        
        int ans = matrix[row2][col2];
        
        if(row1 -1 >= 0){
            // cout << matrix[row1-1][col2] << " ";
            ans -= matrix[row1-1][col2];
        }
        
        if(col1-1 >=0 ){
            // cout << matrix[row2][col1-1] << " ";
            ans -= matrix[row2][col1-1];
        }
        
        if(row1-1 >= 0 && col1-1 >=0 )
            ans+=matrix[row1-1][col1-1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */