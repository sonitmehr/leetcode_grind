class Solution {
public:
    int dp[46];
    int solve(int i,int n){
        if(i > n)return 0;
        if(i == n)return 1;
        if(dp[i] != -1)return dp[i];
        int one = solve(i + 1,n);
        int two = solve(i + 2,n);

        return dp[i] = one + two;
    }

    int climbStairs(int n) {
        


        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        for(int i= 2;i<=n;i++){
            
            int one = dp[i - 1];
            int two = dp[i - 2];

            dp[i] = one + two;
        }

        return dp[n];
    }
};
