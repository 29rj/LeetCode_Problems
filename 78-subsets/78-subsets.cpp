class Solution {
public:
   
    vector<vector<int>> subsets(vector<int>& nums) {
        
        function<void(set<vector<int>>&,int,vector<int>&,vector<int>)> helper = [&](set<vector<int>>&ans,int curr,vector<int>&nums,vector<int>vec){
            
            if(curr == nums.size()){
                ans.insert(vec);
                return;
            }
            
            vec.push_back(nums[curr]);
            helper(ans,curr+1,nums,vec);
            vec.pop_back();
            helper(ans,curr+1,nums,vec);
        };
        
        set<vector<int>>ans;
        vector<int>vec;
        helper(ans,0,nums,vec);
        
        vector<vector<int>>fans(ans.begin(),ans.end());
        return fans;
    }
};