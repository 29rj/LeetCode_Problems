class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        
        while(j < s.length()){
            
            if(s[j] == ' '){
                reverse(s.begin()+i,s.begin()+j);
                i = j+1;
            }
            
            j++;
            
            if(j == s.length()){
                
                reverse(s.begin()+i,s.begin()+j);
                i = j+1;
            }
        }
        
        return s;
    }
};