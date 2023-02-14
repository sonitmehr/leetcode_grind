class Solution {
public:
    int dp[30001][2];
    int f(int i,int buy,vector<int>&a){
        
        if(i >= a.size())return 0;

        int one = -1e9;
        if(dp[i][buy] != -1)return dp[i][buy];
        if(buy){
            one = max(-a[i] + f(i + 1,0,a),f(i + 1,1,a));
        }
        // sell
        else {
            one = max(a[i] + f(i+1,1,a),f(i + 1,0,a));
        }
        return dp[i][buy] = one;
        
    }

    int maxProfit(vector<int>& prices) {
        //memset(dp,-1,sizeof(dp));
        int n = prices.size();
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int i = n - 1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                int one = 0;
                if(buy){
                    one = max(-prices[i] + dp[i + 1][0],dp[i+1][1]);
                }
                else{
                    one = max(prices[i] + dp[i+1][1],dp[i+1][0]);
                }
                dp[i][buy] = one;
            }
            
        }
        return dp[0][1];
    }
};
