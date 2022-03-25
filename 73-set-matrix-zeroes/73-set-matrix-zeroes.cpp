class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        
        unordered_map<int,int>mpi,mpj;
        
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j] == 0){
                    mpi[i]++;
                    mpj[j]++;
                }
            }
        }
        
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                
                if(mpi.find(i) != mpi.end())
                    m[i][j] = 0;
                
                if(mpj.find(j) != mpj.end())
                    m[i][j] = 0;
            }
        }
    }
};