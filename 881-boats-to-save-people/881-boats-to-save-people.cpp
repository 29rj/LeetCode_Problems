class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int n = p.size();
        n--;
        int i,j;
        sort(p.begin(),p.end());
        //i-->bigger,j-->smaller
        //we r always letting go 
        for(i=0,j=n;i<=j;j--){
            
            if(p[i]+p[j]<=limit)
                i++;
        }
        
        return n-j;
    }
};