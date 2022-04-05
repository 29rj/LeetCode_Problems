class Solution {
public:
    
    
    bool checkPalindrome(string st){
        
        string rev = st;
        reverse(st.begin(),st.end());
        return st == rev;
    }
    
    void checkPartition(string str , int st , vector<vector<string>>&ans , vector<string>&vec){
        
        if(st == str.length()){
            ans.push_back(vec);
        }
        
        for(int i=st; i < str.length(); i++){
            
            if(checkPalindrome(str.substr(st,i-st+1))){
                vec.push_back( str.substr(st,i-st+1) );
                checkPartition(str, i + 1 , ans , vec);
                vec.pop_back();
            }   
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans;
        vector<string> vec;
        checkPartition(s,0,ans,vec);
        return ans;
        
    }
};