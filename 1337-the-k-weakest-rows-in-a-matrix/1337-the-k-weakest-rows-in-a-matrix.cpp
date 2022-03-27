class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        multiset<pair<int,int>>st;
        
        for(int i=0;i<mat.size();i++){
            
            int count = 0;
            
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1)
                    count++;
            }
            st.insert({count,i});
        }
        
        vector<int>ans(k);
        
        int i = 0;
        
        for(auto&it:st){
            if(i>=k)
                break;
            ans[i++] = it.second;
        }
        
        return ans;
    }
};