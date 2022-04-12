// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k)
    {
       vector<int>vec(n);
       for(int i=0;i<n;i++)
            vec[i] = i+1;
        
        int i = 0;
        k--;
        while(vec.size()!=1){
            int in = (i+k)%(vec.size());
            vec.erase(vec.begin()+in);
            
            i=in;
        }
        
        return vec[0];
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends