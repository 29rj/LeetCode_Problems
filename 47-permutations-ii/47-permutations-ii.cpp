class Solution {
public:
    
    void helper(vector<int> &nums,set<vector<int>> &ans,vector<int> &vec,map<int,int> &mp) {
        
        if(vec.size() == nums.size()){
            ans.insert(vec);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(mp.find(i) == mp.end()){
                mp[i]++;
                vec.push_back(nums[i]);
                helper(nums,ans,vec,mp);
                vec.pop_back();
                mp.erase(i);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>ans;
        
        map<int,int>mp;
        
        vector<int>vec;
        
        helper(nums,ans,vec,mp);
        
        vector<vector<int>>oans(ans.begin(),ans.end());
        
        return oans;
    }
};