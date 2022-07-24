class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        if(p.size() == 1 ||p.size() == 0)
            return 0;
        
        int n = p.size();
        
        vector<int>dp(n);
        
        int sum = p[1] > p[0] ? p[1]-p[0] : 0;
        
        for(int i=1;i+1<n;i++) {
            
            int temp;
            
            if(p[i+1] > p[i]){
                temp = sum + p[i+1]-p[i];
            }else{
                temp = sum;
            }
            
            sum = temp;
        }
        
        return sum;
    }
};