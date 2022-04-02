class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal)
    {
        vector<int>vis(1001,0);
        
        queue<long>q;
        
        q.push(start);
        
        int cnt = 1;
        
        while(!q.empty())
        { 
            int m = q.size();
            
            while(m--)
            {
                auto curr = q.front();
                
                q.pop();
                
                if( vis[curr] == 1 )
                    continue;
                
                vis[curr]=1;

                for(int i=0;i<nums.size();i++)
                {
                    long a = nums[i]+curr;
                    
                    if(a==goal)return cnt;

                    if(a>=0 && a<=1000 && vis[a]==0)
                    {
                        // vis[a]=1;
                        q.push(a);
                    }

                    long b = curr - nums[i];
                    if(b==goal)return cnt;

                    if(b>=0 && b<=1000 && vis[b]==0 )
                    {
                        // vis[b]=1;
                        q.push(b);
                    }

                    long c = curr^nums[i];
                    if(c==goal)return cnt;

                    if( c>=0 && c<=1000 && vis[c]==0 )
                    {
                        // vis[c]=1;
                        q.push(c);
                    }
                }
            }
            
            cnt++;   
        }
        
        return -1;
    }
};