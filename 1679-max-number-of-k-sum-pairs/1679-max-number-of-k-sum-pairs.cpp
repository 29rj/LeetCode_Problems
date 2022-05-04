class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int i =0,j=nums.size(),count=0;;
        j--;
        
        while(i<j){
            if(nums[i]+nums[j] < k){
                i++;
            }
            else if(nums[i]+nums[j]>k){
                j--;
            }
            else{
                count++;
                i++,j--;
            }
        }
        
        return count;
    }
};