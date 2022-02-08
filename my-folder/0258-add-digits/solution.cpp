class Solution {
public:
    
   
    
    int addDigits(int num) {
        int sum = 0;
        while(num >0){
            int digit = num%10;
            sum = sum + digit;
            num = num/10;
            
        }
        if(sum<10)return sum;
        return addDigits(sum);
        
        
        
        
        /*if(num == 0){
            return 0;
        }if(num%9 == 0){
            return 9;
        }
        return num%9;        
        
        
        
        
        
        
        
        
        
        */
        
    }
};
