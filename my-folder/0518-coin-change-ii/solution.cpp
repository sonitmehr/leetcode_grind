class Solution {
public:
    int change(int amount, vector<int>& v) {
        int n = v.size();

        vector<vector<int>> dp(n,vector<int>(amount + 1,0));


        for(int i = 0;i<=amount;i++){
            if(i % v[0] == 0)dp[0][i] = 1;
        }

        for(int i = 1;i<n;i++){
            for(int j = 0;j<=amount;j++){
                if(j - v[i] >= 0) dp[i][j] += dp[i][j - v[i]]; 
                dp[i][j] += dp[i - 1][j];
            }
        }

        return dp[n - 1][amount];


    }
};
