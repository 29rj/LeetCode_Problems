class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        
        //Brute force --> O(n*n) time and space )(1)
        
        //O(n) space and time both --> moore's vooting algorithm
        
        int c = 0,ele;
        for(int i=0;i<nums.size();i++){
            if(c==0)
                ele = nums[i];
            if(ele == nums[i])
                c++;
            else
                c--;
        }
        
        return ele;
    }
};