class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        ans={{1}};
        
        if(numRows == 1)
            return ans;
        
        ans.push_back({1,1});
        
        if(numRows == 2)
            return ans;
        
        numRows -= 2;
        
        vector<int>prev={1,1};
        
        while(numRows--) {
            
            int i=0,j=0;
            vector<int>now;
            now.push_back(1);
            
            for(int i=0;i+1<prev.size();i++){
                now.push_back(prev[i]+prev[i+1]);
            }
            
            now.push_back(1);
            ans.push_back(now);
            prev = now;
        }
        
        return ans;
    }
};