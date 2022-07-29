class Solution {
public:
    
    bool one(string now,string pattern){
        
         unordered_map<char,char>mp;
            
            bool ch = true;
                
            for(int i=0;i<now.size();i++){
                
                if(mp.find(now[i]) != mp.end()){
                    
                    char prev = mp[now[i]];//a
                    
                    if(prev != pattern[i]){
                        ch = false;
                        break;
                    }
                    
                }else{
                    mp[now[i]] = pattern[i];
                }
            }
        
        return ch;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>ans;
        
        int plen = pattern.length();
        
        for(int i=0;i<words.size();i++){
            
            string now = words[i];
            
            if(now.length() != plen)
                continue;
            
            if(one(now,pattern) && one(pattern,now))
                ans.push_back(now);
        }
        
        return ans;
    }
};