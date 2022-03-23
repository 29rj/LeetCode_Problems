// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str){
        
        int n = pattern.length() , m = str.length();
        
        vector<vector<bool>>dp(n+1,vector<bool>(m+1));
    
        for(int i=n;i>=0;i--){//
            for(int j=m;j>=0;j--){//
                
                if(i == n && j == m){
                    dp[i][j] = 1;
                }
                else if( i == n){//
                    dp[i][j] = 0;
                }
                else if(j == m){
                    if(pattern[i] =='*')
                        dp[i][j] = dp[i+1][j];
                    else 
                        dp[i][j] = 0;
                }
                else{
                    if(pattern[i] == '*'){
                        dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    }
                    else if(pattern[i] == '?'){
                        dp[i][j] = dp[i+1][j+1];
                    }
                    else{
                        if(str[j] == pattern[i]){
                            dp[i][j] = dp[i+1][j+1];
                        } 
                        else
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        return dp[0][0];
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends