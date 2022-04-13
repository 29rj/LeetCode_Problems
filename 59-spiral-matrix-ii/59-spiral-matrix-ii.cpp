class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sti = 0, eni = n-1, stj = 0 ,enj=n-1,count=1;
        vector<vector<int>>vec(n,vector<int>(n));
        
        while(sti<=eni && stj<=enj){
            //top
            for(int j=stj;j<=enj;j++){
                vec[sti][j] = count++;
            }
            sti++;
            
            //right
            for(int i=sti;i<=eni;i++){
                vec[i][enj] = count++;
            }
            enj--;
            
            //down
            for(int j=enj;j>=stj;j--){
                vec[eni][j] = count++;
            }
            eni--;
            
            //left
            for(int i=eni;i>=sti;i--){
                vec[i][stj] = count++;
            }
            stj++;
        }
        
        return vec;
    }
};