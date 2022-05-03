class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int>vec(nums.begin(),nums.end());
        sort(vec.begin(),vec.end());
        
        int n = nums.size();
        int i=0,j=n-1;
        
        for(;i<n;i++){
            if(nums[i] != vec[i])
                break;
        }
        
        for(;j>=0;j--){
            if(nums[j] != vec[j])
                break;
        }
        
        return max(j-i+1,0);
    }
};