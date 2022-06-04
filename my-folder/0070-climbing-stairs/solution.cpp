class Solution {
public:
    int f(int ind,vector<int> &dp){
        if(ind == 0)return 1;
        else if(ind == 1)return 1;
        if(dp[ind]!=-1)return dp[ind];
        
        int l = f(ind-2,dp);
        int r = f(ind-1,dp);
        return dp[ind] = r+l;
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int prev2 = 1,prev1 =1;
        //int curr = 2;
        for(int i = 2;i<=n;i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
