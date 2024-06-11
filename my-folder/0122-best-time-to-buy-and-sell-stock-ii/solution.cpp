class Solution {
public:

    int solve(int i,int isBought,vector<int> &prices){
        
        if(i == prices.size()){
            return 0;
        }

        int one = -1e9,two = -1e9;
        if(isBought == 0){
            one = max(-prices[i]  + solve(i + 1,1,prices),solve(i + 1,0,prices));

        }
        else{
            one = max(prices[i] + solve(i + 1,0,prices),solve(i + 1,1,prices));
        }
        return one;
    }

    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(2,0));

        for(int i = n - 1;i>=0;i--){
            for(int buy = 0;buy <=1;buy++){
                if(buy == 0){
                    dp[i][buy] = max(-prices[i] + dp[i + 1][1],dp[i + 1][0]);
                }
                else{
                    dp[i][buy] = max(prices[i] + dp[i + 1][0],dp[i + 1][1]);
                }
            }
        }
        return dp[0][0];
    }
};
