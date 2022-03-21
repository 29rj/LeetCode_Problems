class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]] = i;
        }
        
        int last = -1,start=0;
        vector<int>ans;
        
        for(int i=0;i<s.length();i++){
            
            last = max(last,mp[s[i]]);
            
            if(last == i){
                ans.push_back(last-start+1);
                start = i+1;
                last = -1;
            }
        }
        
        // ans.push_back(last-start+1);
        
        return ans;
        
    }
};