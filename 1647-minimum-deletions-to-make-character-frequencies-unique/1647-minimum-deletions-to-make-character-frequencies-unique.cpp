class Solution {
public:
    int minDeletions(string s) {
        
        vector<int>arr;
        
        for(char ch='a';ch<='z';ch++){
            int cn = count(s.begin(),s.end(),ch);
            arr.push_back(cn);
        }
        
        sort(arr.begin(),arr.end());
        
//         for(auto&it:arr){
//             cout << it << " ";
//         }
        
//         cout << endl;
        
        int ans = 0;
        
        for(int i=24;i>=0;i--) {
            
            if(arr[i] == 0)
                break;
            
            if(arr[i] < arr[i+1])
                continue;
            
            int temp = arr[i];
            
            arr[i] = max(0,arr[i+1]-1);
            
            ans += (temp-arr[i]);
            
           
            
            // cout << i << " " << arr[i] << " \n";
        }
        
        return ans;
    }
};