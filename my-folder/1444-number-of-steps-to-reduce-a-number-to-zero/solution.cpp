class Solution {
public:
    int numberOfSteps(int num) {
        long long val = __builtin_popcount(num);
        if(num == 0)return 0;
        long long k = log2(num);
        
        return k + val;
    }
};
