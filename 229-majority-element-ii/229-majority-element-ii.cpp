class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        int c1 = 0 , c2 = 0 , num1 , num2;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == num1){
                c1++;
            }
            else if(nums[i] == num2){
                num2 = nums[i];
                c2++;
            }
            else if(c1 == 0){
                num1 = nums[i];
                c1=1;
            }
            else if(c2 == 0){
                num2 = nums[i];
                c2=1;
            }
            else{
                c1--,c2--;
            }
        }
        
        cout << num1 << " " << num2 << "\n";
        
        c1 = 0 ,c2 = 0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == num1)
                c1++;
            if(nums[i] == num2)
                c2++;
        }
        
        vector<int>ans;
        if(c1 > n/3)
            ans.push_back(num1);
        
        if(c2 > n/3 )
            ans.push_back(num2);
        return ans;
        
    }
};