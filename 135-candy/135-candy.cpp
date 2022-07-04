class Solution {
public:
    int candy(vector<int>& arr) {
        
        int n = arr.size(),sum = 0;
        
        vector<int>right(n,1),left(n,1);
        
        //left
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        
        //right
        for(int i=n-2;i>=0;i--){
            if(arr[i] > arr[i+1]){
                right[i] = right[i+1] + 1;
            }
        }
        
        for(int i=0;i<arr.size();i++){
            // cout << left[i] << " " << right[i] << "\n";
            sum += max(left[i],right[i]);
        }
        
        return sum;
    }
};