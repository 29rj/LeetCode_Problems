class Solution {
public:
    unordered_map<int,vector<char>>vec;
    
    bool isValid(int i, int j){
        
        for(int k=0;k<26;k++){
            if(vec[i][k] != 0 && vec[j][k] !=0)
                return false;
        }
        
        return true;
    }
    
    int maxProduct(vector<string>& words) {
        
        for(int i=0;i<words.size();i++){
            
            vector<char>ch(26,0);
            
            for(int j=0;j<words[i].length();j++){
                char now = words[i][j]-'a';
                ch[now]++;
            }
            vec[i] = ch;
        }
        
        int maxi = 0;
        
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                
                if(isValid(i,j)){
                    int currLength = words[i].length()*words[j].length();
                    maxi = max(currLength,maxi);
                }
            }
        }
        
        return maxi;
    }
};