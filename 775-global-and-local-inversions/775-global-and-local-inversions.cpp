class Solution {
public:
    
    #define ll long long
    
    ll merge(vector<int>&nums,int st,int end){
        
        ll temp[nums.size()];
        
        ll mid = (st+end)/2;
        
        ll i=st,j=mid+1;
        
        ll count = 0,k=st;
        
        while(i<=mid && j<=end){
            
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                count += (mid-i+1);
                temp[k++] = nums[j++];
            }
        }
        
        while(j<=end){
            temp[k++] = nums[j++];
        }
        
        while(i<=mid){
            temp[k++]  = nums[i++];
        }
        
        for(i=st;i<=end;i++){
            nums[i] = temp[i];
        }
        
        return count;
        
    }
    
    ll mergeSort(vector<int>&nums,int st,int end){
        
        int count = 0;
        
        if(st<end){
            
            ll mid = (st+end)/2;
            
            count+=mergeSort(nums,st,mid);
            
            count+=mergeSort(nums,mid+1,end);
            
            count+=merge(nums,st,end);
        }
        
        return count;
    }
    
    bool isIdealPermutation(vector<int>& nums) {
        
//         ll gb,lc=0;
        
//         ll n = nums.size();
        
//         for(int i=0;i+1<nums.size();i++){
            
//             if(nums[i]>nums[i+1])
//                 lc++;
//         }
        
//         gb = mergeSort(nums,0,n-1);
        
//         return (gb == lc);
        
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]-i)>1)
                return false;
        }
        return true;
    }
};