class Solution {
public:
    unordered_map<string,string>mp1,mp2;
    int i=1;
    // Encodes a URL to a shortened URL.
    string nextCode(){
        return to_string(i++);
    }
    
    string encode(string longUrl) {
        string code = nextCode();
        mp1[longUrl]=code;
        mp2[code]=longUrl;
        
        return mp1[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));