class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        
        vector<int>graph[n];
        
        vector<int>in(n,0);
        
        for(auto&pre:preq){
            graph[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }
        
        
        queue<int>q;
        
        //toposort
        
        //1. Push those into which have 0 in-degree
        for(int i=0;i<n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>topo;
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            
            topo.push_back(tp);
            
            for(auto&it:graph[tp]){
                in[it]--;
                if(in[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(topo.size() != n){
            topo.clear();
        }
        
        return topo;
        
    }
};