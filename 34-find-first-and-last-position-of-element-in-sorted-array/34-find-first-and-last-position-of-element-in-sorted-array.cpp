class Solution {
public:
    
    int searchIndex(vector<int>&nums,int tar) {
        
        int st = 0,end = nums.size();
        
        end--;
        
        while(st <= end) {
            
            int mid = (st+end)/2;
            
            if(nums[mid] == tar){
                return mid;
            }else if(nums[mid] < tar){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans;
        
        int in = searchIndex(nums,target);
        
        int st = in,end = in;
        
        int temp = in-1;
        
        while(temp >= 0 && in !=-1){
            
            if(nums[temp] != nums[st])
                break;
            st = temp;
            temp--;
        }
        
        temp = in+1;
        
        while(temp < nums.size() && in !=-1){
            
            if(nums[temp] != nums[end]){
                break;
            }
            
            end = temp;
            temp++;
        }
        
        ans.push_back(st);
        ans.push_back(end);
        
        return ans;
    }
};