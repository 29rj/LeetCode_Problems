class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> newMat(matrix[0].size(),vector<int>(matrix.size()));
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                newMat[j][i] = matrix[i][j];
            }
        }
        return newMat;
    }
};