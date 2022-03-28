class Solution {
public:
    #define ll long long
    double myPow(double x, int n) {
        
        double ans = 1.0000;
        
        /*
        //Brute force --> O(N)
        for(int i=0;i<abs(n);i++){
            ans *= x;
        }
        
        if(n<0)
            ans = (double)1.0000/(ans);*/
        
        //Binary Exponentiation
        
        ll tempn = abs(n);
        
        while(tempn > 0){
            
            if(tempn % 2 == 0){
                x = x*x;
                tempn /=2;
            }else{
                tempn--;
                ans = ans*x;
            }
        }
        
        if(n < 0)
            ans = (double)1.0000/ans;
        
        return ans;
    }
};