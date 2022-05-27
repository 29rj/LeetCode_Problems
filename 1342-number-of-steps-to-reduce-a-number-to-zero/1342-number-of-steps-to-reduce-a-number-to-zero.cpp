class Solution {
public:
    int numberOfSteps(int num) {
        auto cn = [](int num){
            int count=0;
            while(num>0){
                if(num%2==0){
                    num /=2;
                }else{
                    num--;
                }
                count++;
            }
            
            return count;
        };
        
        return cn(num);
    }
};