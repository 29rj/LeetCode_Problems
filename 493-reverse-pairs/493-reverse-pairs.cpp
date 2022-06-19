class Solution {
public:
    
    #define ll long long
    
    ll merge(vector<int>&nums,int st,int mid,int en){
        
        ll temp[nums.size()];
        
        ll cn = 0, i = st,j = mid+1 , k = st;
        
        while(i<=mid && j<=en){
            if((ll)nums[i] > (ll)nums[j]*2){
                cn += (mid-i+1);
                j++;
            }else{
                i++;
            }
        }
        
        i=st,j=mid+1;
        
        while(i<=mid && j<=en){
            
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        
        while(j<=en){
            temp[k++] = nums[j++];
        }
        
        while(i<=mid){
            temp[k++]  = nums[i++];
        }
        
        for(i=st;i<=en;i++){
            nums[i] = temp[i];
        }
        
        return cn;
    }
    
    ll mergeSort(vector<int>&nums,int i,int j){
        
        if(i>=j)
            return 0;
        
        ll cn = 0;
        
        ll mid = (i+j)/2;
        
        cn += mergeSort(nums,i,mid);
        
        cn += mergeSort(nums,mid+1,j);
        
        cn += merge(nums,i,mid,j);
        
        return cn;
        
    }
    
    
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        
        int ans = mergeSort(nums,0,n-1);
        
        return ans;
    }
};