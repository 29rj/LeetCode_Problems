class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[&](vector<int>&e1,vector<int>&e2){
            return e1[1] < e2[1] || (e1[1] == e2[1] && e1[0] < e2[0]);
        });
        
        set<int>days;
        
        for(int i=1;i<=100000;i++){
            days.insert(i);
        }
        
        int cn = 0;
        
        for(auto&it:events){
            int s = it[0] , e = it[1];
            
            auto itr = days.lower_bound(s);
            
            if(itr == days.end() || *itr > e){
                continue;
            }
            ++cn;
            days.erase(*itr);
        }
        
        return cn;
    }
};