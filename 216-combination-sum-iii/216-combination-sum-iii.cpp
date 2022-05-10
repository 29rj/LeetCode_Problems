class Solution {
public:
    vector<vector<int>>ans;
    set<int>used;
    
    void helper(int n,int k,int st){
        
        if(k == 0){
            if(n == 0){
                vector<int>vec(used.begin(),used.end());
                ans.push_back(vec);
                return;
            }
        }
        
      
        for(int i=st;i<=9;i++){
            used.insert(i);
            helper(n-i,k-1,i+1);
            used.erase(i);
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        helper(n,k,1);
        // vector<vector<int>>now(ans.begin(),ans.end());
        used.clear();
        return ans;
    }
};