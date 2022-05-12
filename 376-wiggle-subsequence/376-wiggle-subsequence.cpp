class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        vector<pair<int,int>>dp(nums.size(),{0,0});
        
        int mxlen=0;
        
        for(int i=1;i<nums.size();i++) {
            
            int mneg=0,mpos=0;
            
            for(int j=i-1;j>=0;j--) {
                
                pair<int,int> pr = dp[j];
                
                if(nums[i]-nums[j] > 0){
                    mpos = max(mpos,pr.second+1);
                }
                else if(nums[i]-nums[j] < 0){
                    mneg = max(mneg,pr.first+1);
                }else{
                    mneg = max(mneg,pr.second),mpos = max(mpos,pr.first);
                }
            }
            
            pair<int,int>now(mpos,mneg);
            
            dp[i] = now;
            
            mxlen = max(mxlen,max(mpos,mneg));
        }
        
        return mxlen+1;
    }
};