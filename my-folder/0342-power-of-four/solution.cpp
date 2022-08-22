class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1)return true;
        if( n < 0)return false;
        
        double a = sqrt(n);
       // cout << INT_MAX << endl;
        if(a!=(int)a)return false;
        
        if(__builtin_popcount(a)==1)return true;
        return false;
        
    }
};
