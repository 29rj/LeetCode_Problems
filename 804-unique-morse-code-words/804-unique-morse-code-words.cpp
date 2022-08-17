class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words){
        
        vector<string>vec = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int cn = 0;
        
        unordered_set<string>stk;
        
        for(auto&it:words){
            
            string now = "";
            
            for(int i=0;i<it.length();i++){
                now += vec[it[i]-'a'];
            }
            
            stk.insert(now);
        }
        
        return stk.size();
        
    }
};