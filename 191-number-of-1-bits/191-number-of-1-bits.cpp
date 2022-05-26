class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        string bs = bitset<32>(n).to_string();
        cout << bs << "\n";
        
        auto cn = [](string s){
            int cn=0;
            for(int i=0;i<s.size();i++){
                if(s[i] == '1')
                    cn++;
            }
            
            return cn;
        };
        
        return cn(bs);
        // return k;
        
    }
};