class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        vector<int>dp(nums.size(),INT_MIN);
        
        multiset<int>s({dp[0] = nums[0]});
        
        for(int i=1;i<nums.size();i++){
            
            if(i > k){
                s.erase(s.find(dp[i-k-1]));
            }
            
            s.insert(dp[i] = *rbegin(s) + nums[i]);
        }
        
        return dp.back();
        
//         vector<int> dp(nums.size(),INT_MIN);
        
//         dp[0] = nums[0];
        
//         for(int i=1;i<nums.size();i++){
//             for(int j=1;j<=k && i-j>=0;j++){
//                 dp[i] = max(dp[i],dp[i-j]+nums[i]);
//             }
//         }
        
//         return dp.back();
    }
};