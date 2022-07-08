class Solution {
public:
    
    int mx = 1e7+1;
    int dp[100][100][21];
    
    int helper(vector<int>&houses, vector<vector<int>>&cost ,int &target, int currH,int countN,int prevH){
        
        //base case
        if(currH == houses.size())
            return countN == target ? 0 : mx;
        
        if(currH > houses.size())
            return mx;
        
        if(dp[currH][countN][prevH] != -1)
            return dp[currH][countN][prevH];
        
        int mn = mx;
        
        if(houses[currH]) { // If the curr house is already painted
            
            //If the prevHouses is painted differently than the currHouse --> then currN is increased by 1.
            if(houses[currH] != prevH)
                mn = helper(houses,cost,target,currH+1,countN+1,houses[currH]);
            else
                mn = helper(houses,cost,target,currH+1,countN,houses[currH]);
                
        }else{
            
            // i --> No of houses 
            // Trying all 'i' different colors with 'currH' and taking possible situations. 
            // Since color is from 1-index therefore take 'i+1'

            for(int i=0;i<cost[0].size();i++){
                
                int temp;
                if(i+1 != prevH){
                    temp = cost[currH][i] + helper(houses,cost,target,currH+1,countN+1,i+1);
                }else
                    temp = cost[currH][i] + helper(houses,cost,target,currH+1,countN,i+1);
                
                mn = min(mn,temp);
            }
        }
        
        
        
        return dp[currH][countN][prevH] = mn ;
    } 
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = helper(houses,cost,target,0,0,0);
        
        if(ans == mx)
            return -1;
        return ans;
    }
};