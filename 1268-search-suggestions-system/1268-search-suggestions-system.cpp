class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        sort(products.begin(), products.end());
        vector<string>now;
        
        string mt = "";
        
        for(int i=0;i<searchWord.length();i++) {
            
            int cn = 0;
            now.clear();
            mt += searchWord[i];
            
            for(int j=0;j<products.size();j++) {
                
                if(products[j].substr(0,i+1) == mt){
                    now.push_back(products[j]);
                    cn++;
                    if(cn == 3)
                        break;
                }
               
            }
            
            ans.push_back(now);
        }
        
        return ans;
    }
};