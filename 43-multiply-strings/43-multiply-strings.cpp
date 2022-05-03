class Solution {
public:
    
    string sum2string(string s1, string s2){
        
        int n=s1.size(),m=s2.size();
        
        if(n==0)
            return s2;
        if(m==0)
            return s1;
        
        int r=0,i=n-1,j=m-1;
        
        string sum="";
        
        // cout << s1 << " " << s2 << "\n";
        
        while(i >=0 && j >=0){
            int num = r + (s1[i]-'0') + (s2[j]-'0');
            r = num/10;
            num = num % 10;
            // cout << num << " ";
            sum += to_string(num);
            i--,j--;
        }
        
        while(i>=0){
            int num = r + (s1[i]-'0');
            r = num/10;
            num = num % 10;
            sum += to_string(num);
            i--;
        }
        
        while(j>=0){
            int num = r + (s2[j]-'0');
            r = num/10;
            num = num % 10;
            sum += to_string(num);
            j--;
        }
        
        if(r != 0)
            sum += to_string(r);
        
        reverse(sum.begin(),sum.end());
        
        return sum;
    }
        
    
    string sumString(vector<string>&ans){
        
        string prev = "";
        
        for(int i=0;i<ans.size();i++){
            string nowsum = sum2string(ans[i],prev);
            // cout << nowsum << "\n";
            prev = nowsum;
        }
        
        return prev;
    }
    
    
    string multiply(string num1, string num2) {
        
        //num2 -> smaller length
        if(num2.length() > num1.length())
            swap(num1,num2);
        
        vector<string>ans;
        
        // cout << num2 << " " << num1 << "\n";
        
        int m = num2.length();
        int n = num1.length();
        
        
        for(int i=m-1;i>=0;i--){
            
            string now="";
            int r=0;
            
            for(int k=0;k<m-i-1;k++){
                now += "0";
            }
            
            for(int j=n-1;j>=0;j--){
                
                int currNum = r + (num1[j]-'0') * (num2[i]-'0');
                r = currNum/10;
                currNum = currNum%10;
                now += to_string(currNum);
            }
            
            if(r != 0)
                now += to_string(r);
            
            reverse(now.begin(),now.end());
            
            ans.push_back(now);
        }
        
        string finalAns = sumString(ans);
    
        
//         for(auto&it:ans)
//             cout << it << " ";
        
        if(finalAns[0] == '0')
            return "0";
        
        return finalAns;
    }
};