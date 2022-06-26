class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        
        vector<int>prefix,suffix;
        
        int sum1=0,sum2=0,n = cp.size();
        
        for(int i=0;i<cp.size();i++){
            
            sum1 += cp[i];
            sum2 += cp[n-i-1];
            
            prefix.push_back(sum1);
            suffix.push_back(sum2);
        }
        
        reverse(suffix.begin(),suffix.end());
        
        // for(int i=0;i<n;i++){
        //     cout << prefix[i] << " ";
        // }
        
        int i=0,mx = -1;
        
        while(i <= k) {
            
            int num1 = INT_MIN, num2 = INT_MIN;
            
            if(i-1 >= 0)
                num1  = prefix[i-1];
            
            if(n-k+i < n)
                num2 = suffix[n-k+i];
            
            // cout << num1 << " " << num2 << "\n";
            
            if(num1 == INT_MIN){
                mx = max(mx,num2);
            }else if(num2 == INT_MIN){
                mx = max(mx,num1);
            }else
                mx = max(mx,num1+num2);
            
            i++;
        }
        
        return mx;
    }
};