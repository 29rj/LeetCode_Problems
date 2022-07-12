class Solution {
public:
    int a,b,c,d;
    
    int helper(vector<int>&ms,int i){
         if(i==ms.size()) {
                
                if(a == b && b == c && c == d && a == 0){
                    return true;
                }
                
                return false;
            }
            
            if(ms[i]<=a){
                
                a -= ms[i];
                if(helper(ms,i+1))
                   return true;
                a += ms[i];
            }
            
            if(ms[i]<=b){
                
                b -= ms[i];
                if(helper(ms,i+1))
                   return true;
                b += ms[i];
            }
            
            if(ms[i]<=c){
                
                c -= ms[i];
                 if(helper(ms,i+1))
                   return true;
                c += ms[i];
            }
            
            if(ms[i]<=d){
                
                d -= ms[i];
                if(helper(ms,i+1))
                   return true;
                d += ms[i];
            }
            
            return false;
    }
    
    bool makesquare(vector<int>& ms) {
        
        int sum = accumulate(ms.begin(),ms.end(),0);
        
        if(sum%4 != 0)
            return false;
        
        sum /= 4;
        
        a=sum,b=sum,c=sum,d=sum;
        
        sort(ms.rbegin(),ms.rend());
        
        return helper(ms,0);
    }
};