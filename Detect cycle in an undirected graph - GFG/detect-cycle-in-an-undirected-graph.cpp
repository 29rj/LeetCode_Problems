// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> graph[]) {
        
        vector<bool>vis(V,false);
        
        function<bool(vector<int>[],vector<bool>&,int,int)> dfs = [&](vector<int>graph[],vector<bool>&vis,int node,int par) {
            
            for(auto&it:graph[node]){
                if(!vis[it]){
                    vis[it]=true;
                    if(dfs(graph,vis,it,node))
                        return true;
                }else if( it != par){
                    return true;
                }
            }
            
            return false;
        };
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i] = true;
                if(dfs(graph,vis,i,-1))
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