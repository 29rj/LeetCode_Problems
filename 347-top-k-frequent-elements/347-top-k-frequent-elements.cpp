class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        
        for(auto&it:nums)
            mp[it]++;
        
        multimap<int,int,greater<int>>mlp;
        
        for(auto&it:mp){
            mlp.insert(pair<int,int>(it.second,it.first));
            
        }
        
        vector<int>ans;
        
        for(auto&it:mlp){
            // cout << it.first << " " << it.second << "\n";
            ans.push_back(it.second);
            k--;
            if(k==0)
                break;
        }
    
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};