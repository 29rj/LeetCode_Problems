class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>stk;
        for(int i=(int)(nums2.size())-1;i>=0 ;i--){
            stk.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++) {
            
            stack<int>now = stk;
            
            while(now.top() != nums1[i]){
                now.pop();
            }
            
            // cout << now.top() << "\n";
            
            while(!now.empty() && now.top() <= nums1[i]){
                now.pop();
            }
            
            if(now.empty())
                nums1[i] = -1;
            else
                nums1[i] = now.top();
        }
        
        return nums1;
    }
};