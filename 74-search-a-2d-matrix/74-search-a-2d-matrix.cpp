class Solution {
public:
    
    bool bs(vector<vector<int>>& mat , int target ,int row){
        
        int st=0,end=mat[0].size();
        end--;
        
        while(st<=end){
            int mid = (st+end)/2;
            
            if(mat[row][mid] == target)
                return true;
            else if(mat[row][mid] > target){
                end = mid-1;
            }
            else
                st = mid+1;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int row = -1 , col = mat[0].size();
        col--;
        
        for(int i=0;i<mat.size();i++){
            
            if(target < mat[i][col] ){
                row = i;
                break;
            }
            else if(target == mat[i][col])
                return true;
        }
        
        if(row == -1)
            return false;
        
        return bs(mat,target,row);
    }
};