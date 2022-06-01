class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        function<bool(vector<vector<int>>&,vector<int>&,int,int)> dfs = [&](vector<vector<int>>&graph,vector<int>&color,int c,int node){
            
            color[node] = c;
            
            for(int j=0;j<graph[node].size();j++){
                
                if(color[graph[node][j]] == -1){
                    
                    int k = c^1;
                    
                    if(!dfs(graph,color,k,graph[node][j]))
                        return false;
                    
                }else if(color[graph[node][j]] == color[node]){
                    return false;
                }
            }
            
            return true;
        };
        
        vector<int>color(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++){
            if(color[i] == -1){
                if(!dfs(graph,color,0,i))
                {
                    // for(auto&it:color){
                    //     cout << it << " ";
                    // }
                    return false;
                }

            }
        }
        
        // for(auto&it:color){
        //     cout << it << " ";
        // }
        
        return true;
    }
};