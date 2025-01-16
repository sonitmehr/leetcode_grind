class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int need = __builtin_popcount(num1);
        int bits = __builtin_popcount(num2);
        // cout << "bits : " << bits << endl;

        int ans = 0;
        if (bits >= need) {

            int add = 1;
            int k = 0;
            while (k < 32 && bits > 0) {
                if (num1 & (1 << k)) {
                    ans += add;
                    bits--;
                }
                k++;
                add <<= 1;
                // cout << ans << " " << ans << endl;
            }
            k = 0;
            add = 1;
            while (bits > 0) {
                if (!(num1 & (1 << k))) {
                    // cout << "unset : " << k << endl;
                    ans += add;
                    bits--;
                }
                k++;
                add <<= 1;
            }
        }
        else{
            // cout << "else ::: " <<endl;
            int k = 30;
            int add = pow(2,k);
            while (k >= 0 && bits > 0) {
                if (num1 & (1 << k)) {
                    ans += add;
                    bits--;
                }
                k--;
                add >>= 1;
                // cout << ans << " " << ans << endl;
            }
        }

        return ans;
    }
};
