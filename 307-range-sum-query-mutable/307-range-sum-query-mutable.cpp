// class NumArray {
    
    
// public:
//     vector<int>seg;
//     int sz;
//     NumArray(vector<int>& nums) {
//         sz = nums.size();
//         seg.resize(4*sz);
        
//         build(nums,0,sz-1,0);
//     }
    
//     int build(vector<int>&nums,int ss,int se,int node) {
        
//         if(ss == se){
//             seg[node] = nums[ss];
//             return seg[node];
//         }
        
//         int mid = (ss+se)/2;
        
//         int leftBuild = build(nums,ss,mid,2*node+1);
//         int rightBuild = build(nums,mid+1,se,2*node+2);
        
//         return nums[node] = leftBuild + rightBuild;
//     }
    
//     void update(int index, int val) {
//         update(index,val,0,sz-1,0);
//     }
    
//     int update(int index,int val,int ss,int se,int node){
        
//         if(index < ss || index > se){
//             return seg[node];
//         }
        
//         if(ss == se){
//             seg[node] = val;
//             return val;
//         }
        
//         int mid = (ss+se)/2;
        
//         int leftUpdate = update(index,val,ss,mid,2*node+1);
//         int rightUpdate = update(index,val,mid+1,se,2*node+2);
        
//         seg[node] = leftUpdate+rightUpdate;
        
//         return seg[node];
//     }
    
//     int sumRange(int left, int right) {
//         return sumRange(left,right,0,sz-1,0);
//     }
    
//     int sumRange(int left,int right,int ss,int se,int node){
        
//         if(left > se || right < ss)
//             return 0;
        
//         if(left <= ss && se <= right)
//             return seg[node];
        
//         int mid = (ss+se)/2;
        
//         int leftSum = sumRange(left,right,ss,mid,2*node+1);
//         int rightSum = sumRange(left,right,mid+1,se,2*node+2);
        
//         return leftSum + rightSum;
//     }
// };

// /**
//  * Your NumArray object will be instantiated and called as such:
//  * NumArray* obj = new NumArray(nums);
//  * obj->update(index,val);
//  * int param_2 = obj->sumRange(left,right);
//  */


class NumArray {
    private:
    vector<int>numsArray;
    int low;
    int high;
public:
    void build(int ind,int low,int high,vector<int>&nums)
    {
        if(low==high)
        {numsArray[ind]=nums[low];
         return;}
        else
        {
            int mid=(low+high)/2;
            build(2*ind+1,low,mid,nums);
            build(2*ind+2,mid+1,high,nums);
            numsArray[ind]=numsArray[2*ind+1]+numsArray[2*ind+2];
        }
        
    }
    int update_index(int ind,int index,int new_val,int low,int high)
    {
          if(low==index && high==index)
              return numsArray[ind]=new_val;
          if(low>index || high<index)
              return numsArray[ind];
          int mid=(low+high)/2;
        
        int left=update_index(2*ind+1,index,new_val,low,mid);
        int right=update_index(2*ind+2,index,new_val,mid+1,high);
        return numsArray[ind]=left+right;
        
    }
    int query(int ind,int l,int r,int low,int high)
    {
        if(low>r ||high<l)
            return 0;
        if(l<=low && r>=high)
            return numsArray[ind];
        int mid=(low+high)/2;
        int left=query(2*ind+1,l,r,low,mid);
       int right= query(2*ind+2,l,r,mid+1,high);
        return left+right;
    }
    NumArray(vector<int>& nums) {
        numsArray.resize(4*nums.size(),0);
        low=0;
        high=nums.size()-1;
        build(0,low,high,nums);
        // cout<<"Constructor"<<endl;
        // print();
       
    }
    
    void update(int index, int val) {

          update_index(0,index,val,low,high);
        // cout<<"Update"<<endl;
        // print();
        
    }
    
    int sumRange(int left, int right) {
       return  query(0,left,right,low,high);
      
      
    }
    
};