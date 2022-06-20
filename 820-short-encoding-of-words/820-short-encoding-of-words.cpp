class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        sort(words.begin(),words.end(),[](string &s1,string &s2)
        { 
            return s1.length() > s2.length();
        });
        
        string res="";
        
        res = res + words[0] + "#";
        
        for(int i=1;i<words.size();i++) {
            
           int pos = res.find(words[i]+"#");
            
           if(pos == -1){
               res += words[i]+"#";
           }
        }
        
        return res.length();
    }
};