class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9 + 7;
    int solve (int n,int k){
        if(n == 0)return 0;
        if(k == 0)return 1;

        if(dp[n][k] != -1)return dp[n][k];
        int count = 0;
        for(int i = 0;i<=min(n - 1,k);i++){
            count = (count + solve(n - 1,k-i))%mod; 
        }

        return dp[n][k] = count;
        
    }
   

    int kInversePairs(int n, int k) {
        // [1,2,3]

        // [2,1,3]
        
        // [1,3,_]
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};
