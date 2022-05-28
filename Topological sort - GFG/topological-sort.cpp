// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    function<void(vector<int>[],vector<bool>&,vector<int>&,int)>dfs = [&](vector<int>graph[],vector<bool>&vis,vector<int>&ans,int node){
	        
	        for(auto&it:graph[node]){
	            if(!vis[it]){
	                vis[it] = true;
	                dfs(graph,vis,ans,it);
	            }
	        }
	        
	        ans.push_back(node);
	    };
	    
	    vector<bool>vis(V,false);
	    vector<int>ans;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            vis[i] = true;
	            dfs(adj,vis,ans,i);
	        }
	    }
	    
	   // for(int i=0;i<ans.size();i++){
	   //     cout << ans[i] << " ";
	   // }
	   
	   reverse(ans.begin(),ans.end());
	   
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends