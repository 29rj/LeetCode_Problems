class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //Method 1: Using sort(0 --> (NlogN) 
        //Method 2: Using counting 1 and 2 , O(N) + O(N) --> O(2N) 
        //Method 3: Dutch National Flag Algorithm
        
        int low = 0,mid = 0,high = nums.size();
        high--;
        
        while(mid <= high){
            
            if(nums[mid] == 1)
                mid++;
            else if(nums[mid] == 2) {
                swap(nums[mid],nums[high--]);
            }
            else {
                swap(nums[mid++],nums[low++]);
            }
        }
        
    }
};