class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr = 0;
        
        for(int i=1;i<=nums.size();i++){
            xr ^=i;
            xr ^= nums[i-1];
        }
        
        return xr;
    }
};