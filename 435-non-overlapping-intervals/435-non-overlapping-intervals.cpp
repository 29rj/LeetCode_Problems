class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        
        sort(begin(a), end(a));
        
        int prev = a[0][1];
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(prev > a[i][0]) {
                ans++;
                prev = min(prev, a[i][1]);
            }else prev = a[i][1];
        }
        
        return ans;
    }
};