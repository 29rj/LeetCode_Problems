class Solution {
public:
    string simplifyPath(string s) {
        
        //remove consecutive slashes
        int i=0 , st = 0;
        int len = s.length();
        
        while(i < len){
            
            if(s[i] == '/' && s[i+1] =='/'){
                s = s.substr(0,i)+s.substr(i+1);
            }
            else
                i++;
            
            len = s.length();
        }
        
        i = 1 ;
        
        stack<string>stk;
        string now;
        while(i < s.length()){
            
            if(s[i] == '/'){
                
                now  = s.substr(st+1,i-st-1);
                // cout << now << "\n";
                st = i;
                if(now == ".."){
                    if(!stk.empty())
                        stk.pop();
                }
                else{
                    // cout << "wow" << "\n";
                    if(now != ".")
                        stk.push(now);
                }
            }
            
            i++;
        }
        
        now  = s.substr(st+1,i-st-1);
        
        if(now == ".."){
            if(!stk.empty())
                stk.pop();
        }
        else{
            if(now != "." && !now.empty())
                stk.push(now);
        }
        
        // cout << "sz " << stk.size() << "\n";
        
        vector<string>ans;
        
        while(!stk.empty()){
            cout << stk.top() << "\n";
            ans.push_back(stk.top());
            stk.pop();
        }
        
        s = "/";
        
        for(int i=ans.size()-1;i>=0;i--){
            s += ans[i];
            if(i!=0)
                s+="/";
        }
        
        return s;
    }
    
   
};