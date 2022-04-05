class Solution {
public:
    int maxArea(vector<int>& ht) {
        
        int i=0,j=ht.size();
        j--;
        int mx = 0;
        
        while(i<j){
            mx = max(mx,(j-i)*min(ht[i],ht[j]));
            
            if(ht[i] <= ht[j]){
                i++;
            }
            else
                j--;
        }
        
        return mx;
    }
};