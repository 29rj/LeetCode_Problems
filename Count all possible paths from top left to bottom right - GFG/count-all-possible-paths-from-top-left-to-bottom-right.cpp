// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int M = 1e9+7;
    
    long long int helper(int i,int j,int m,int n) {
        
        if( i == m && j == n )
            return 1;
            
        if( i > m || j > n )
            return 0;
        
        return (helper(i+1,j,m,n)%M + helper(i,j+1,m,n)%M )%M;

    }
    
    long long int numberOfPaths(int m, int n) {
        
        // return helper(1,1,m,n);
        
        //dp
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(j-1>=0)
                    dp[i][j] = dp[i][j-1]%M;
                if(i-1>=0)
                    dp[i][j] = (dp[i][j] +  dp[i-1][j])%M;
                    
                // dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends