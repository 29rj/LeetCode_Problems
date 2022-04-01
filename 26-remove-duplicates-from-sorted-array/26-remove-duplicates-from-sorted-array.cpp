class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int rep = 0 , len = nums.size(), i = 0;
        set<int>stk;
        
        while(i < nums.size() ){
           stk.insert(nums[i++]);
        }
        
        rep = stk.size();
        
        i=0;
        for(auto &it : stk){
            nums[i++] = it;
        }
        
        return rep;
        
    }
    
};