class Solution {
public:
    int MOD = 1e9 + 7;
    
    long f(int n,int k,vector<vector<int>> &dp){
        if(k ==0 )return 1;
        if(k < 0)return 0;
        if(n <= 0)return 0;
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        long long sum = (f(n-1, k,dp) + f(n, k-1,dp)- f(n-1, k-n,dp) + MOD)%MOD;
        
        return dp[n][k] = sum%MOD;
        
    }
    
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(n,k,dp);
    }
};
