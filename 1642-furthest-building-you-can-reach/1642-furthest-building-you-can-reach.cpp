class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int i=0;
        
        for(i=0;i+1<heights.size();i++){
            
            int diff = heights[i+1] - heights[i];
            
            if(diff > 0) pq.push(diff);
            
            if(pq.size() > ladders){
                bricks -= (pq.top());
                pq.pop();
                if(bricks < 0 )
                    break;
            }
            
        }
        
        return i;
    }
};