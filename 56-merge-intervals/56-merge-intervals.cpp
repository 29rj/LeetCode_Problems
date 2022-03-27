class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ir) {
        
        vector<vector<int>>ans;
        sort(ir.begin(),ir.end());
        
        ans.push_back(ir[0]);
        
        int i = 0;
        
        while(i < ir.size()){
            int curr = ans.size();
            curr--;
            
            if(ir[i][0] > ans[curr][1]){
                ans.push_back(ir[i]);
            }
            else if(ir[i][0] >= ans[curr][0] && ir[i][1] > ans[curr][1]){
                ans[curr][1] = ir[i][1];
            }
            
            i++;
            
        }
        
        return ans;
    }
};