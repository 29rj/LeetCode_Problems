class Solution {
public:
    
    #define ll long long
    
    ll merge(vector<int>&nums,int st,int end){
        
        ll temp[nums.size()];
        
        ll mid = (st+end)/2;
        
        ll i=st,j=mid+1;
        
        ll count = 0,k=st;
        
        while(i<= mid && j<=end){
        
            
            if((ll)nums[i] > (ll)2*nums[j]){
                count += (mid-i+1);
                j++;
            }
            else
                i++;
        }
        
        i=st,j=mid+1;
        
        while(i<=mid && j<=end){
            
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
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
        
        if(st>=end)return 0;
        
        
            
            ll mid = (st+end)/2;
            
            count+=mergeSort(nums,st,mid);
            
            count+=mergeSort(nums,mid+1,end);
            
            count+=merge(nums,st,end);
       
        
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
       
       int num = mergeSort(nums,0,n-1);
        
         for(auto&it:nums)
            cout << it << " ";
        
        cout << "\n";
        
        return num;
        
    }
};