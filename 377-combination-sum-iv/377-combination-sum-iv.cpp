class Solution {
public:
    unordered_map<int,int>mp;
    
    int helper(vector<int>& nums, int sum, int target){
        
        if(sum > target){
            return 0;
        }
        
        if(sum == target)
            return 1;
        
        if(mp.find(sum) != mp.end())
            return mp[sum];
        
        int total = 0;
        
        for(int i=0;i<nums.size();i++){
            total += helper(nums,sum+nums[i],target);
        }
        
        mp[sum] = total;  
        
        return total;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        
        return helper(nums,0,target);   
    }
};