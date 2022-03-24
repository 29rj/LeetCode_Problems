// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public: 

    vector<vector<int>>dp;
    
    bool isPalindrome(string st){
        
        int n = st.length() , i = 0;
        n--;
        
        while(i<n){
            if(st[i++] != st[n--])
                return false;
        }
        
        return true;
    }
    
    int helper(string st , int s ,int end){
        
        if(s >= end || isPalindrome(st.substr(s,end-s+1)))
            return 0;
        
        if(dp[s][end] != -1)
            return dp[s][end];
            
        int mn = INT_MAX;
        
        for(int k=s;k<end;k++){
            
            int ans1 = 0 , ans2 = 0;
            
            if(dp[s][k] != -1)
                ans1 = dp[s][k];
            else
                ans1 = helper(st,s,k);
                
            if(dp[k+1][end] != -1)
                ans2 = dp[k+1][end];
            else
                ans2 = helper(st,k+1,end);
            
            mn = min(mn,ans1+ans2+1);
        }
        
        dp[s][end] = mn;
        
        return mn;
        
    }
    
    int palindromicPartition(string str)
    {
        int n = str.length();
        
        dp.resize(501,vector<int>(501,-1));
    
        n--;
        
        return helper(str,0,n);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends