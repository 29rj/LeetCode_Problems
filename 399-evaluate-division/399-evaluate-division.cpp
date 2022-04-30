// class Solution {
// public:
//     vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
//         map<pair<string,string>,double>mp;
        
//         for(int i=0;i<queries.size();i++){
//             mp[{queries[i][0],queries[i][1]}] = -1;
            
//             if(queries[i][0] == queries[i][1])
//                 mp[{queries[i][0],queries[i][1]}] = 1.00000;
//         }
        
//         for(int i=0;i<eq.size();i++){
//             for(int j=0;j<eq.size();j++){
//                 // cout << "run" << " ";
//                 // cout << eq[i][1] << " " << eq[j][0] << "\n";
//                 if(i!=j && eq[i][1] == eq[j][0]){
                    
//                     // cout << eq[i][0] << " " << eq[i][1] << "\n";
                    
//                     if(mp.find({eq[i][0],eq[j][1]}) != mp.end()){
//                         mp[{eq[i][0],eq[j][1]}] = values[i]*values[j];
//                     }
                   
//                 }
//                 else if(i == j){
//                     if(mp.find({eq[i][1],eq[i][0]}) != mp.end()){
//                         mp[{eq[i][1],eq[i][0]}] = 1.0/values[i];
//                     }
//                 }
//             }
//         }
        
//         vector<double>ans;
        
//         for(int i=0;i<queries.size();i++){
//             ans.push_back(mp[{queries[i][0],queries[i][1]}]);
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
void dfs(string start,string end,map<string,double>& mp,map<string,vector<string>>& graph,double& val,map<string,int>& visited,bool& found){
        visited[start]=1;
    
        if(found==true)
            return ;
        for(auto child:graph[start]){
            if(visited[child]!=1){
                // cout<<start<<" "<<child<<"\n";
                val*=mp[start+"->"+child];
                if(end==child){
                    // cout<<end<<" -- "<<child<<"\n";
                    found=true;
                    return ;
                }
                dfs(child,end,mp,graph,val,visited,found);
                if(found==true){
                    return ;
                }
                else{
                    val/=mp[start+"->"+child];
                }
            }
        }
       
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string,double> mp;
        map<string,vector<string>> graph;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u+"->"+v]=values[i];
            mp[v+"->"+u]=1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++){
            string start=queries[i][0];
            string end=queries[i][1];
            if(graph.find(start)==graph.end()||graph.find(end)==graph.end()){
                ans.push_back(-1);
            }
            else{
                // ans.push_back(1);
                double val=1;
                map<string,int> visited;
                bool found=false;
                if(start==end){
                    found=true;
                }
                else
                dfs(start,end,mp,graph,val,visited,found);
                if(found==true)
                ans.push_back(val);
                else
                    ans.push_back(-1);
                
            }
        }
        return ans;
    }
};