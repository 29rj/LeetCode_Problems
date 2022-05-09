class Solution {
public:
    
    int fact(int n){
        
        if(n == 1)
            return 1;
        
        return fact(n-1)*n;
    }
    
    
    int countNumbersWithUniqueDigits(int n) {
        
        long long int osum = 1;
        
        for(int i=1;i<=n;i++) {
            
            long long int sum = 9;
            
            int n = 9;
            
            for(int j=1; j<=i-1;j++) {
                sum *= n;
                n--;
            }
            
            if(i == 1) {
                osum += 9;
            }
            else {
                osum += sum;
            } 
        }
        
        return osum;
    }
};