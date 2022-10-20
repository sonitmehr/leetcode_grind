class Solution {
public:
    
    int M = 1e9 + 7;
    long long f(int i,vector<long long> &dp){
        
        if(i == 1)return dp[i] = 2;
        if(i == 2)return dp[i] = 3;
        
        
        if(dp[i] != -1)return dp[i];
        
        int l =  f(i-2,dp)%M;
        int r = 0 + f(i-1,dp)%M;
        
        return dp[i] = (l%M + r%M)%M;
    }
    
    int countHousePlacements(int n) {
        vector<long long> dp(n+1,-1);
        f(n,dp);
        return dp[n]*dp[n]%M;
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i = 2;i<n;i++){
        //     dp[i] = dp[i-1] + 1 + dp[i-2];
        // }
        // return dp[n-1];
    }
};
