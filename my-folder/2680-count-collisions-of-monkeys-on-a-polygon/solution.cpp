class Solution {
public:
    long long M = 1e9 + 7;
    long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res%M * res%M * a%M;
    else
        return res%M * res%M;
}
    int monkeyMove(int n) {
        long long ans = 1;
        ans = binpow(2,n);
        return (ans + M - 2)%M;
    }
};
