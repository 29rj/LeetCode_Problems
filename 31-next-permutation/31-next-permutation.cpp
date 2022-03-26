class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size();
        i -= 2;
        
        for(;i>=0; i--){
            
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        
        if(i<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            int l = nums.size();
            l--;
            
            while(l>i){
                if(nums[l] > nums[i])
                    break;
                l--;
            }
            
            if(l>0)
                swap(nums[i],nums[l]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};