class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(auto&it:stones){
            pq.push(it);
        }
        
        while(!pq.empty() && !(pq.size() == 1)){
            int tp1 = pq.top();
            pq.pop();
            int tp2 = pq.top();
            pq.pop();
            
            if(abs(tp1-tp2)!=0){
                pq.push(abs(tp1-tp2));
            }
        }
        
        if(pq.size()==0)
            return 0;
        return pq.top();
    }
};