class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0,t1 = 1,t2 = 1;
        int ans = 0;
        if(n == 0)return t0;
        if(n <= 2)return 1;
        for(int i = 3;i<=n;i++){
            ans = (t0 + t1 + t2);
            t0 = t1;
            t1 = t2;
            t2 = ans;
        }
        return ans;
    } // 0 1 1 2
};
