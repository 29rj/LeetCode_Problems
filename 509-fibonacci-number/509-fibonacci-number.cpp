class Solution {
public:
    int fib(int n) {
        int prev = 1 , prevTo = 0 , curr = 1;
         
        if(n == 0 || n == 1)
            return n;
        
        n--;
       
        while(n--){
            curr = prevTo + prev;
            prevTo = prev;
            prev = curr;
        }
        
        return curr;
    }
};