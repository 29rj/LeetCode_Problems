// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int helper(vector<int>& arr ,int N ,int  i, int res, int K){
        if(i == N){
            if(res == K)
                return 1;
            else
                return 0;
        }
        
        return helper(arr,N,i+1,res^arr[i],K) + helper(arr,N,i+1,res,K);
    }
    
    int subsetXOR(vector<int> arr, int N, int K) {
        int result=0;
        return helper(arr,N,0,result,K);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends