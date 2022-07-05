class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx = 0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(mp.find(nums[i]-1) == mp.end()){
                
                int st = nums[i]+1,cn=1;
                
                while(mp.find(st) != mp.end()){
                    st++;
                    cn++;
                }
                
                mx = max(mx,cn);
                
            }
        }
        
        return mx;
    }
};