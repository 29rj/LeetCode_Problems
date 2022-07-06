class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int m = nums1.size(),n = nums2.size();
        
        int low = 0,high = m,mid = (m+n+1)/2;
        
        while(low <= high){
            
            int ct1 = (low+high)>>1;
            
            int ct2 = mid-ct1;
            
            int l1,l2,r1,r2;
            
            if(ct1 == 0)
                l1 = INT_MIN;
            else
                l1 = nums1[ct1-1];
            
            if(ct2 == 0)
                l2 = INT_MIN;
            else
                l2 = nums2[ct2-1];
            
            if(ct1 == m)
                r1 = INT_MAX;
            else
                r1 = nums1[ct1];
            
            if(ct2 == n)
                r2 = INT_MAX;
            else
                r2 = nums2[ct2];
            
            if(l1 <= r2 && l2 <= r1){
                if((m+n)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }else{
                    return max(l1,l2);
                }
            }else if(l1>r2){
                high = ct1-1;
            }else
                low = ct1+1;
            
        }
        return 0.0;
    }
};