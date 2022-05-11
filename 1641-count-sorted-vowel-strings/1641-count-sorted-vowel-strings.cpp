class Solution {
public:
    int countVowelStrings(int n) {
        
        //Initialisng our result with 0 for n = 0
        vector<int64_t>ans(5,1);
        
        for(int i=1;  i < n; i++){
            for(int j=3; j >=0 ; j--){
                ans[j] += ans[j+1];
            }
        }
        
        return std::accumulate(ans.begin(),ans.end(),0);
     
    }
};