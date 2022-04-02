// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	
	
	int helper(int coins[],int n, int V,int dp[]){
	    
	    if(V == 0)
	        return 0;
	        
	    if(dp[V] != -1)
	        return dp[V];
	    
	    int oans = INT_MAX;
	    
	    for(int i=0;i<n;i++){
	        
	        if(V>=coins[i]){
	            
	            int now  = helper(coins,n,V-coins[i],dp);
	        
	            if(now != INT_MAX)
	                oans = min(oans,now+1);
	        }
	    }
	    
	    dp[V] = oans;
	    
	    return oans;
	}
	
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[V+1];
	    
	    memset(dp,-1,sizeof(dp));
	    
	    int ans = helper(coins,M,V,dp);
	    
	    if(ans == INT_MAX)
	        return -1;
	        
	    return ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends