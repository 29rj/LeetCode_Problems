// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool>vis(V,false);
        
        auto bfs_isCycle = [](vector<int>graph[],vector<bool>&vis,int i){
            queue<pair<int,int>>q;
            q.push({i,-1});
            
            vis[i] = true;
            
            while(!q.empty()){
                
                pair<int,int>now = q.front();
                q.pop();
                
                int node = now.first;
                int par = now.second;
                
                for(auto&it:graph[node]){
                    if(!vis[it]){
                        vis[it] = true;
                        q.push({it,node});
                    }else if(it != par){
                        return true;
                    }
                }
            }
            
            return false;
        };
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs_isCycle(adj,vis,i))
                    return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends