// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int st[], int e[], int n)
    {
        unordered_set<int>stk;
        vector<pair<int,int>>vec;
        
        for(int i=0;i<n;i++){
            vec.push_back({e[i],st[i]});
        }
        
        sort(vec.begin(),vec.end());
        
        int limit = vec[0].first;
        
        stk.insert(vec[0].second);
        
        for(int i=1;i<n;i++){
            
            if(vec[i].second > limit){
                limit = vec[i].first;
                stk.insert(vec[i].second);
            }
        }
        
        return stk.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends