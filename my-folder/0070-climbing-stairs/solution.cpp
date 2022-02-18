class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1; // number of ways to climb the zeroth step will be one
        dp[1]=1; // number of ways to climb the first step will be one
        for(int i=2;i<=n;i++){
           dp[i] = dp[i-1]+dp[i-2]; //for finding the number of ways to climb the second step we will add the number of ways to climb the zeroth and first step
        }
        return dp[n];// returning the number of ways to climb 5 steps will be the addition of number of ways to climb step 4 and 3
    }
};
