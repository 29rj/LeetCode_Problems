class Solution {
public:
    void helper(vector<int>&nums,int i,set<vector<int>> &ans){
        if(i == nums.size()){
            ans.insert(nums);
            return;
        }
        
        for(int st=i;st<nums.size();st++){
            swap(nums[st],nums[i]);
            helper(nums,i+1,ans);
            swap(nums[st],nums[i]);
        }
            
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>ans;
      
        helper(nums,0,ans);
        
        vector<vector<int>>now(ans.begin(),ans.end());
        
        return now;
    }
};