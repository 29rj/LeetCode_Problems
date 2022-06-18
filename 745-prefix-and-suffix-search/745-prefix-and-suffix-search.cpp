class WordFilter {
public:
    unordered_map<string,int>mp;
        
    WordFilter(vector<string>& words) {
        
        for(int i=0;i<words.size();i++){
            string word = words[i];
            
            for(int j=0;j<word.size();j++){
                string s = word.substr(0,j+1);
                
                for(int k=0;k<word.size();k++){
                    string p = word.substr(k);
                    mp[s+'|'+p] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string str = prefix+'|'+suffix;
        
        if(mp.find(str) != mp.end()){
            return mp[str];
        }
        
        return -1;
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */