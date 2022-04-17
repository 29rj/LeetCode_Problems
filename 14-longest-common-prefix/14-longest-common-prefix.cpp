class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //brute force
        
        if(strs.size() == 1)
            return strs[0];
        string cn="";
        
        int i=0,j=0;
        while(i<strs[0].length() && j < strs[1].length() && strs[0][i] == strs[1][j]){
            cn += strs[0][i];
            i++,j++;   
        }
        
        for(int p=2;p<strs.size();p++){
            int k = 0;
            while(k < strs[p].length() && k < cn.length() && cn[k] == strs[p][k]){
                k++;
            }
            
            cn = cn.substr(0,k);
        }
        
        return cn;
    }
};