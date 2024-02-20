class Solution {
public:
    // int dp[10001];
    // int solve(int n){
    //     if(n <= 0)return 0;
    //     int ans = 1e9;
    //     if(dp[n] != -1)return dp[n];
    //     for(int i = 1;i*i <= n;i ++){
    //         ans = min(ans,1 + solve(n - i*i));
    //     }

    //     return dp[n] = ans;
    // }


    int numSquares(int n) {
        vector<int> dp(n + 1,0);

        for(int i = 1;i<=n;i++){
            int ans = 1e9;
            for(int j = 1;j*j <= i;j ++){
                ans = min(ans, 1 + dp[i - j*j]);
            }
            dp[i] = ans;
        }   
        return dp[n];
    }
};
