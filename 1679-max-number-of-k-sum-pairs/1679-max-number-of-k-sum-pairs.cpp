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
//                 if(nums[j] == nums[j-1] || nums[i] == nums[i+1]){
//                     int k = j;
                    
//                     while(k>i+1 && nums[k]==nums[k-1]){
//                         // count++;
//                         k--;
//                     }
                    
//                     i++;
//                     // count++;
//                 }
                {
                    count++;
                    i++,j--;
                }
            }
        }
        
        return count;
    }
};