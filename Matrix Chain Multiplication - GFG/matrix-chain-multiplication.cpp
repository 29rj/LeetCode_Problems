// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>dp;
    
    int mcm_helper(int arr[],int N,int st,int end){
        if(st >= end)
            return 0;
            
        if(dp[st][end] != -1)
            return dp[st][end];
            
        int mn = INT_MAX;
        
        for(int k=st;k<end;k++){
            
            int tempans = mcm_helper(arr,N,st,k) + mcm_helper(arr,N,k+1,end) + arr[st-1]*arr[k]*arr[end];
            mn = min(mn,tempans);
        }
        
        dp[st][end] = mn;
        
        return mn;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
       dp.resize(N,vector<int>(N,-1));
       return mcm_helper(arr,N,1,N-1);
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