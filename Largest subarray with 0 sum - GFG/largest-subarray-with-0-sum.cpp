// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mp;
        int prev = A[0];
        
        mp[prev] = 0;
        mp[0] = -1;
        
        int mx = 0;
        bool ch;
        
        if(prev == 0)
            ch = true;
        else
            ch = false;
        
        for(int i=1;i<n;i++){
            
            prev += A[i];
            
            if(mp.find(prev) != mp.end()){
                mx = max(i-mp[prev],mx);
            }
            else{
                mp[prev] = i;
            }
        }
        
        if(mx != 0)
            return mx;
        if(ch)
            return 1;
        return 0;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends