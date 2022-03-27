class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        vector<int>num;
        int i=0,j=0;
        
        while(i<m && j<n){
            
            if(num1[i]>num2[j]){
                num.push_back(num2[j++]);
            }
            else
                num.push_back(num1[i++]);
        }
        
        while(i<m)
            num.push_back(num1[i++]);
        
        while(j<n)
            num.push_back(num2[j++]);
        
        num1 = num;
    }
};