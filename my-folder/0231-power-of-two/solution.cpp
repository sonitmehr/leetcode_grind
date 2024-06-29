class Solution {
public:
    bool isPowerOfTwo(int n) {
        long x = n;
        if(n == 0)return false;
        if(n == 1)return true;
        // Removing the last set bit.
        // (x & -x) will have the last set bit from left.
        // x - (x & -x) is us removing this last set bit 
        return x - (x & -(x - 1)) == 0;
    }
};
