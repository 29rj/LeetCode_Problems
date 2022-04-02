class Solution {
public:
    
    void helper(vector<int>nums,set<vector<int>>&ans,int i,vector<int>now){
        
        if(i == nums.size()){
            sort(now.begin(),now.end());
            ans.insert(now);
            return;
        }
        
        helper(nums,ans,i+1,now);
        
        now.push_back(nums[i]);
        
        helper(nums,ans,i+1,now);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>>ans;
        vector<int>now;
        helper(nums,ans,0,now);
        vector<vector<int>>vec(ans.begin(),ans.end());
        return vec;
        
    }
};