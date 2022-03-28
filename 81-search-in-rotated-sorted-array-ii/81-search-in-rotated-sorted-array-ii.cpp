class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(nums[0] == target || (nums.size() == 2 && nums[1] == target))
            return true;
        
        if(target >= nums[0]){
            int i=0;
            while(i+1 < nums.size() && nums[i+1]>=nums[i]){
                if(nums[i]==target || nums[i+1] == target)
                    return true;
                i++;
            }
        }
        else{
            
            // cout << "second" << "\n";
            int i=nums.size();
            i--;
            
            if(nums[i] == target)
                return true;
            
            while(i-1 >= 0 && nums[i-1] <= nums[i]){
                // cout <<  nums[i] << " " << i << " \n";
                if(nums[i] == target || nums[i-1] == target)
                    return true;
                
                i--;
            }
        }
        
        return false;
    }
    
   
};