class Solution {
public:
    
    int f(vector<int>r){
        int n = r.size(),sum=0;
        
        for(int i=1;i+1<r.size();i++){
            
            int cn1 = 0,cn2=0 ;
            
            for(int j=0;j<i;j++){
                if(r[j] < r[i])
                    cn1++;
            }
            
            for(int j=i+1;j<n;j++){
                if(r[j] > r[i]){
                    cn2++;
                }
            }
            
            // cout << cn1 << " " << cn2 << " \n";
            
            sum += (cn1*cn2);
        }
        
        return sum;
    }
    
    int numTeams(vector<int>& r) {
        
        int sum = 0,n = r.size();
        
        sum += f(r);
        reverse(r.begin(),r.end());
        sum += f(r);
        return sum;
    }
};