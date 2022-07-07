class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto lower = [&](vector<int>&nums,int target){
            
            int st = 0, end = nums.size();
            
            while(st < end){
                
                int mid = (st+end)/2;
                
                if(target <= nums[mid]){
                    end = mid;
                }else{
                    st = mid+1;
                }
            }
            
            return st;
        };
        
        auto upper = [&](vector<int>&nums,int target){
            
            int st = 0,end = nums.size();
            
            while(st < end){
                int mid = (st+end)/2;
                
                if(target < nums[mid]) {
                    end = mid;
                }else{
                    st = mid+1;
                }
            }
            
            return st;
        };
        
        vector<int>ans;
        
        int lw = lower(nums,target);
        int upr = upper(nums,target);
        
        if( lw == upr )
            return {-1,-1};
        
        ans.push_back(lw);
        ans.push_back(upr-1);
        return ans;
    }
};