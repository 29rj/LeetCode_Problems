class Solution {
public:
    void helper(vector<int>& can,int tar,set<vector<int>>&res,vector<int>now){
        
        if(tar == 0){
            sort(now.begin(),now.end());
            res.insert(now);
            return;
        }
        
        if(tar < 0)
            return;
        
        for(int i=0;i<can.size();i++){
            now.push_back(can[i]);
            helper(can,tar-can[i],res,now);
            now.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        
        set<vector<int>>res;
        vector<int>now;
        helper(can,tar,res,now);
        vector<vector<int>>vec(res.begin(),res.end());
        return vec;
    }
};