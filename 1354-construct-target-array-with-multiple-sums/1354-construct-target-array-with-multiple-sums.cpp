class Solution {
public:
    bool isPossible(vector<int>& tar) {
        
        priority_queue<long long>pq;
        
        long long sum = 0;
        
        for(int i=0;i<tar.size();i++){
            pq.push(tar[i]);
            sum += tar[i];
        }
        
        while(pq.top()!=1){
            
            long long curr = pq.top();
            pq.pop();
            
            sum -= curr;
            
            if(sum <=0 || sum >= curr){
                return false;
            }
            
            curr = curr % sum;
            
            if(curr == 0 && sum != 1)
                return false;
            
            pq.push(curr);
            
            sum += curr;
            
        }
        
        return true;
    }
};