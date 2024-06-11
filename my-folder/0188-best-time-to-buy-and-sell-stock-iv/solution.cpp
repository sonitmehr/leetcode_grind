class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
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
        return dp[0][0][k];
    }
};
