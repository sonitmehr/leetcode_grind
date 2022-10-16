class Solution {
public:
    int rev(int n){
        int reverse=0, rem;    

      while(n!=0)    
      {    
         rem=n%10;      
         reverse=reverse*10+rem;    
         n/=10;    
      }  return reverse;
    }
    bool sumOfNumberAndReverse(int n) {
        if(n == 0)return true;
        for(int i = 0;i<n;i++){
            int t = rev(i);
            if(i + t == n){
                //cout << i << " " << t << endl;
                return true;
            }
        }
        return false;
    }
};
