class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int len = needle.length();
        
        if(haystack.length() < needle.length())
            return -1;
        
        for(int i=0;i+len<=haystack.length();i++){
            if(haystack.substr(i,len) == needle)
                return i;
        }
        
        return -1;
    }
};