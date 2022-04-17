class Solution {
public:
    int myAtoi(string s) {
        long ans = 0,ind=1;
        
        if(s.empty())
            return 0;
        
            int i=0;
            
            i=s.find_first_not_of(' ');
        
            if(i >= s.length())
                return 0;
                
            if(s[i] == '-' || s[i] == '+'){
                ind = (s[i++] == '-')?-1:1;
            }
            
            while(s[i]>='0' && s[i] <= '9'){
                ans = ans*10 + (s[i++]-'0');
                if(ans*ind <=INT_MIN) return INT_MIN;
                if(ans*ind>=INT_MAX) return INT_MAX;
            }
            
            return ans*ind;

    }
};