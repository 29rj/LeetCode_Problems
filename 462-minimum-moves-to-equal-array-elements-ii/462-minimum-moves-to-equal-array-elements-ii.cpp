class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        if(nums.size() == 1)
            return 0;
        
        if(nums.size() == 2)
            return abs(nums[0]-nums[1]);
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int ans = 0,mid;
        
        if(n % 2 == 0){
            mid = (nums[n/2] + nums[n/2-1])/2;
        }else{
            mid = nums[n/2];
        }
        
        
        for(int i=0;i<n;i++){
            ans += abs(nums[i]-mid);
        }
        
        return ans;
    }
};