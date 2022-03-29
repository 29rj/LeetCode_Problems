class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int,int>mp;
        
        mp[nums[0]] = 0;
        
        for(int i=1;i<nums.size();i++){
            
            if(mp.find(tar-nums[i]) != mp.end()){
                vector<int>vec={mp[tar-nums[i]],i};
                return vec;
            }
            else{
                mp[nums[i]] = i;
            }
        }
        
        vector<int>vec;
        return vec;
        
    }
};