class Solution {
public:
    int solve(int i, int isBought, int k, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
            
            if(k < 0)return -1e9;
        if (prices.size() == i) {
            if (k < 0)
                return -1e9;
            return 0;
        }
        if (dp[i][isBought][k] != -1)
            return dp[i][isBought][k];
        int ans = -1e9;
        if (isBought == 0) {
            ans = max(-prices[i] + solve(i + 1, 1, k, prices, dp),
                      solve(i + 1, 0, k, prices, dp));
        } else {
            ans = max(prices[i] + solve(i + 1, 0, k - 1, prices, dp),
                      solve(i + 1, 1, k, prices, dp));
        }
        return dp[i][isBought][k] = ans;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int k = 2;
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        

        for(int i = n - 1;i>=0;i--){
            for(int isBought = 0;isBought <=1;isBought++){
                for(int K = 1;K<=k;K++){
                    if(isBought == 0){
                        dp[i][isBought][K] = max(-prices[i] + dp[i + 1][1][K],dp[i+1][0][K]);
                    }    
                    else{
                        dp[i][isBought][K] = max(prices[i] + dp[i+1][0][K-1],dp[i+1][1][K]);
                    }
                }
            }
        }
        return dp[0][0][2];

    }
};
