struct Node{
    Node *ref[26];
    bool flag = false;
    
    bool isPresent(char ch) {
        
        if(ref[ch-'a'] == nullptr)
            return false;
        
        return true;
    }
    
    void put(char ch){
        ref[ch-'a'] = new Node();
    }
    
    Node *getRef(char ch){
        return ref[ch-'a']; 
    }
    
    bool isTrue(){
        return flag;
    }
    
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        Node *node = root;
        
        for(int i=0;i<word.length();i++){
            
            if(!node->isPresent(word[i])){
                node->put(word[i]);
            }
            
            node = node->getRef(word[i]);
        }
        
        node->flag = true;
    }
    
    bool search(string word) {
        
        Node *node = root;
        
        for(int i=0;i<word.length();i++){
            if(!node->isPresent(word[i]))
                return false;
            node = node->getRef(word[i]);
        }
        
        return node->isTrue();
    }
    
    bool startsWith(string word) {
        
        Node *node = root;
        
        for(int i=0;i<word.length();i++){
            
            if(!node->isPresent(word[i]))
                return false;
            
            node = node->getRef(word[i]);
        }
        
       return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */