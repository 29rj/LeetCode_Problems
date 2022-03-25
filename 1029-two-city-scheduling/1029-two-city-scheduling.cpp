bool cmp(const vector<int>&v1,const vector<int>&v2){
        return (v2[1]-v2[0] > v1[1]-v1[0]);
}
    
class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        sort(costs.begin(),costs.end(),cmp);
        int curr = 1, sum = 0;
        
        for(auto&it:costs){
            
            sum += it[0];
            if(curr <= (costs.size()/2))
                sum += (it[1]-it[0]);
            
            curr++;
        }
        
      
        
        return sum;
    }
};