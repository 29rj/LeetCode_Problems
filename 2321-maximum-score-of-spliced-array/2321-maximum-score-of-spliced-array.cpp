class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        
        auto takeOut = [&](vector<int>&nums1,vector<int>&nums2){
            int runSum = 0 , mx = 0;
        
        int totalSum1 = accumulate(nums1.begin(),nums1.end(),0);
        
        for(int i=0;i<nums1.size(); i++){
            
            runSum += (nums2[i] - nums1[i]);
            
            if(runSum < 0)
                runSum = 0;
            
            mx = max(mx,runSum);
        }
            return totalSum1+mx;
        };
        
        
        
        return max(takeOut(nums1,nums2),takeOut(nums2,nums1));
    }
};