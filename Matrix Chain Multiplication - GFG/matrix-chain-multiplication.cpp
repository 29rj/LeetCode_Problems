// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i==j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int mn = 1e9;
        
        for(int k=i;k<j;k++){
            int temp = arr[i-1]*arr[k]*arr[j] + helper(i,k,arr,dp) + helper(k+1,j,arr,dp);
            mn = min(mn,temp);
        }
        
        return dp[i][j] = mn;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        
        return helper(1,N-1,arr,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends