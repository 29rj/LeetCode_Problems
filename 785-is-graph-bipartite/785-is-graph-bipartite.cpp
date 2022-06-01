class Solution {
public:
    
    bool bfs(vector<vector<int>>&graph,int i,vector<int>&color){
        queue<int>q;
        q.push(i);
        color[i]=0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int j=0;j<graph[curr].size();j++){
                
                if(color[graph[curr][j]] == -1){
                    color[graph[curr][j]] = color[curr]^1;
                    q.push(graph[curr][j]);
                }else if(color[graph[curr][j]] == color[curr]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color(graph.size(),-1);
        
        // for(int i=0;i<graph.size();i++){
        //     for(int j=0;j<graph[i].size();j++){
        //         cout << graph[i][j] << " "; 
        //     }
        //     cout << "\n";
        // }
        
        for(int i=0;i<graph.size();i++){
            if(color[i] == -1){
                if(!bfs(graph,i,color)){
                    
                    for(auto&it:color){
                        cout << it << " ";
                    }
        
                    return false;
                }
            }
        }
        
        
        return true;
    }
};