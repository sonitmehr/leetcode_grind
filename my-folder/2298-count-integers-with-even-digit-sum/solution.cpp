class Solution {
public:
    
    int sum(int n){
        int sum1 = 0;
        while(n!=0){
            
            int rem = n %10;
            n = n/10;
            sum1+=rem;
        }
        
        return sum1;
        
    }
    
    int countEven(int num) {
        int count = 0;
        for(int i = 1;i <=num;i++){
            if(sum(i)%2 == 0)count ++;
        }
        return count;
    }
};
