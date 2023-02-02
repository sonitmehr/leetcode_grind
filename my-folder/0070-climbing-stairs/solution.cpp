class Solution {
public:
    int dp[50];
    int f(int i,int n){
        if(i > n)return 0;
        if(i == n)return 1;
        if(dp[i] != -1)return dp[i];
        return dp[i] = f(i + 1,n) + f(i + 2,n);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,n);
    }
};
