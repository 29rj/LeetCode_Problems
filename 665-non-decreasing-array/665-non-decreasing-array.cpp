class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cn = 0;
        
        for(int i=1;i<nums.size();i++){
            
            if(nums[i-1] > nums[i]){
                cn++;
                
                if(i == 1 || nums[i-2] <= nums[i]){
                    nums[i-1] = nums[i];
                }
                else{
                    nums[i] = nums[i-1];
                }
                
                if(cn >= 2)
                    return false;
            }
        }
        
        return true;
    }
};