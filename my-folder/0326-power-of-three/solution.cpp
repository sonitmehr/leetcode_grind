class Solution {
public:
    
    bool isPowerOfThree(int n) {
        int val = 1;
        for(int i = 0;i<19;i++){
            val*=3;
        }
        if(n > 0 && val%n == 0)return true;
        return false;
    }
};
