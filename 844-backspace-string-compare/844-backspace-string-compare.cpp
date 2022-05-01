class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0,j=0;
        stack<char>st1,st2;
        
        while(i<s.size()){
            
            // int j=i;
            
            while( !st1.empty() && s[i] == '#' && i < s.size()){
                // cout << s[i] << " " << i << "\n";
                st1.pop();
                i++;
            }
            
            if(i < s.size() && s[i]!='#'){
                
                st1.push(s[i]);
                // cout << st1.top() << " ";
            }
            
            i++;
        }
        
        cout << st1.size() << " ";
        
        i=0;
        
        while(i<t.size()){
            
            // int j=i;
            
            while( !st2.empty() && t[i] == '#' && i < t.size()){
                st2.pop();
                i++;
            }
            
            if(i < t.size() && t[i]!='#')
                st2.push(t[i]);
            
            i++;
        }
        
        // cout << st2.size() << " ";
        
        if(st1.size() != st2.size())
            return false;
        
        while(!st1.empty()){
            // cout << st1.top() << " " << st2.top() << "\n";
            if(st1.top() != st2.top())
                return false;
            
            // cout << st1.top() << " ";
            
            st1.pop(),st2.pop();
        }

        return true;
        
    }
};