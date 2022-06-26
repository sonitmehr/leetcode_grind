class Solution {
public:
    
    int M = 1e9 + 7;
    long long f(int i,vector<long long> &dp){
        if(i == 0)return 1;
        
        if(i< 0)return 0;
        
        if(dp[i] != -1)return dp[i];
        
        int l = 1 + f(i-2,dp)%M;
        int r = 0 + f(i-1,dp)%M;
        
        return dp[i] = (l%M + r%M)%M;
    }
    
    int countHousePlacements(int n) {
        vector<long long> dp(n,-1);
        long long sum = f(n-1,dp)%M + 1;
        sum = sum% M;
        return (sum * sum)%M;
    }
};
