class Solution {
public:
    int dp[46];
    int f(int i){
        if(i  < 0)return 0;
        if(i == 1) return 1;
        if(i == 2) return 2;
        if(dp[i] != -1)return dp[i];
        int one = 0,two = 0;
        
        return dp[i] =  f(i - 1) + f(i-2);
    }
    int climbStairs(int n) {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        if(n == 1 || n == 2)return n;
        int prev1 = 1,prev2 = 2;
        int curr = 0;
        for(int i = 3;i<=n;i++){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;

        
    }
};
