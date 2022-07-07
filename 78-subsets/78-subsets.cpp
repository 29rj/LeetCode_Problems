class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        function<void(vector<int>&,int,vector<int>,vector<vector<int>>&)> helper = [&](vector<int>&nums,int curr,vector<int>vec,vector<vector<int>>&ans){
            
            ans.push_back(vec);
            
            for(int i=curr;i<nums.size();i++){
                vec.push_back(nums[i]);
                helper(nums,i+1,vec,ans);
                vec.pop_back();
            }
        };
        
        vector<int>vec;
        vector<vector<int>>ans;
        helper(nums,0,vec,ans);
        return ans;
    }
};