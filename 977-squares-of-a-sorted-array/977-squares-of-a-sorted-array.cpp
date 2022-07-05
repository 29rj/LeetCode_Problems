class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int>ans;
        
        int sz = nums.size();
        
        int in1 = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        
        in1--;
        
        // cout << in1 << " ";
        
        in1 = min(sz-1,in1);
        
        int in2 = in1+1;
        
        while(in1 >= 0 && in2 < sz){
            
            if(nums[in1]*nums[in1] < nums[in2]*nums[in2]){
                ans.push_back(nums[in1]*nums[in1]);
                in1--;
            }else{
                ans.push_back(nums[in2]*nums[in2]);
                in2++;
            }
        }
        
        while(in1>=0){
            ans.push_back(nums[in1]*nums[in1]);
            in1--;
        }
        
        while(in2<sz){
            ans.push_back(nums[in2]*nums[in2]);
            in2++;
        }
        
        return ans;
    }
};