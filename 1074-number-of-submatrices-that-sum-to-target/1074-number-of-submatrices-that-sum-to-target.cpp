class Solution {
public:
    
    vector<int>f(int r1,int r2,vector<vector<int>>&matrix){
        
        vector<int>vec;
        
        for(int i=0;i<matrix[0].size();i++){
            if(r1-1>=0)
                vec.push_back(matrix[r2][i]-matrix[r1-1][i]);
            else
                vec.push_back(matrix[r2][i]);
        }
        
        return vec;
    }
    
    int subarrayK(int K,vector<int>vec){
        unordered_map<int,int>mp;
        mp[0]++;
        int sum = 0,cn=0;
        for(int i=0;i<vec.size();i++){
            sum += vec[i];
            cn += mp[sum-K];
            mp[sum]++;
        }
        return cn;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int K) {
        
        int r = matrix.size(),c = matrix[0].size();
        int cn = 0;
        
        for(int i=0;i<c;i++){
            for(int j=1;j<r;j++){
                matrix[j][i] += matrix[j-1][i];
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=i;j<r;j++){
                vector<int>vec = f(i,j,matrix);
                cn += subarrayK(K,vec);
            }
        }
        
        return cn;
        
    }
};