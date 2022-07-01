class Solution {
public:
    int maximumUnits(vector<vector<int>>& bx, int sz) {
        int sum = 0;
        
        sort(bx.begin(),bx.end(),[&](vector<int>&v1,vector<int>&v2){
            return v1[1] > v2[1];
        });
        
        for(auto&it:bx){
            // cout << it[0] << " " << it[1] << "\n";
            if(it[0]<=sz){
                sz -= it[0];
                sum += (it[1]*it[0]);
            }else{
                sum  += (sz*it[1]);
                sz = 0;
            }
        }
        
        return sum;
    }
};