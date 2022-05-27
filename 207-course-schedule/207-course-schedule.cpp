class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& pre) {
        
        vector<bool> vis(V,false), fvis(V,false);
        vector<int>graph[V];
        
        for(int i=0;i<pre.size();i++){
            for(int j=1;j<pre[i].size();j++){
                graph[pre[i][0]].push_back(pre[i][j]);
            }
        }
        
        function<bool(vector<int>[],vector<bool>&,vector<bool>&,int)> dfs_isCycle = [&](vector<int>graph[],vector<bool>&vis,vector<bool>&fvis,int node){
            
            for(auto&it:graph[node]){
                
                if(!vis[it]){
                    vis[it]=true;
                    fvis[it]=true;
                    if(dfs_isCycle(graph,vis,fvis,it))
                        return true;
                    fvis[it]=false;
                    
                }else if(vis[it] && fvis[it]){
                    return true;
                }
            }
            
            return false;
        };
        
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                vis[i]=true;
                fvis[i]=true;
                if(dfs_isCycle(graph,vis,fvis,i)){
                    return false;
                }    
                fvis[i]=false;
            }
        }
        
        return true;
    }
};