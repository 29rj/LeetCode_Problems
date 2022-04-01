class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count = 0 , len = nums.size() , i = 0 ,j = 1;
        
        while(j<nums.size()){;
            
            if(nums[j]!=nums[i]){
                i++;
                nums[i] = nums[j];
                j++;
            }else{
                j++;
            }
        }
        
        return i+1;
    }
    
};