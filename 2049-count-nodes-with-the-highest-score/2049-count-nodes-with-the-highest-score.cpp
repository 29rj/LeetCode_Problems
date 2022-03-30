class Solution {
public:
    
    #define ll long long
    
    ll calSubtree(vector<int>graph[],int curr,vector<int>&sz) {
        ll res = 1;
        
        for(auto &it:graph[curr]){
            res += calSubtree(graph,it,sz);
        }
        
        sz[curr] = res;
        
        return res;
    }
    
    int countHighestScoreNodes(vector<int>& pr) {
    
        //Generating graph
        int n = pr.size();
        vector<int>graph[n];  
        for(int i=1;i<n;i++){
            graph[pr[i]].push_back(i);
        }
        
        //take out size of each subtree
        vector<int>sz(n);
        calSubtree(graph,0,sz);
        
        // for(auto &it: sz){
        //     cout << it << " ";
        // }
        
        int total = sz[0];
      
        unordered_map<ll,ll>mp;
        
        for(int i=0;i<n;i++){
            
            ll mul = 1;
            
            // vector<int>now;
            
            for(auto &it:graph[i]){
                // now.push_back(sz[it]);
                mul *= sz[it];
            }
            
            if(total - sz[i] > 0){
                mul *= (total-sz[i]);
            }
            
            mp[mul]++;
            
        }
        
        ll mx = 1,count = 0;
        
        for(auto &it:mp){
            
            if(it.first >= mx){
                count = it.second;
                mx = it.first;
            }
        }
        
        return count;
        
    }
};