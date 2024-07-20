class Solution {
public:
    int coinChange(vector<int>& v, int amount) {
        int n = v.size();

        vector<vector<int>> dp(n,vector<int>(amount+ 1,1e9));

        for(int am = 0;am<=amount;am++){
            if(am % v[0] == 0) dp[0][am] = am/v[0];
        }

        for(int i= 1;i<n;i++){
            for(int j = 0;j<=amount;j++){
                if(j - v[i] >= 0)dp[i][j] = min(dp[i][j],1 + dp[i][j - v[i]]);
                dp[i][j] = min(dp[i][j],dp[i - 1][j]);
            }
        }

        return dp[n - 1][amount]  == 1e9 ? -1 : dp[n-1][amount];

    }
};
