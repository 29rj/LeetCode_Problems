class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.length();
        
        int i = 0, j=n-1;
       
        while(i < j){
            if(s[i] != s[j]){
                break;
            }
            i++,j--;
        }
        
        if(i>=j)
            return true;
        
        //delete i
        
        string st = s;
        st.erase(i,1);
        n=st.length();
        
        int ni = 0,nj = n-1;
        
        while(ni<nj){
            
            if(st[ni] != st[nj])
                break;
            
            ni++,nj--;
        }
        
        if(ni >= nj)
            return true;
        
        ni=0,nj=n-1;
        st=s;
        st.erase(j,1);
        
        while(ni<nj){
            
            if(st[ni] != st[nj])
                break;
            
            ni++,nj--;
        }
        
        if(ni >= nj)
            return true;
        
        return false;
        
        
    }
};