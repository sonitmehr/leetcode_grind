class Solution {
public:
    
    int f(int i,int buy,int k,vector<int>&a,vector<vector<vector<int>>>&dp){
        if(i == a.size())return 0;
        if(k <= 0)return 0;
        int profit= 0;
        if(dp[i][buy][k] != -1)return dp[i][buy][k];
        if(buy){
            profit = max(-a[i] + f(i + 1,0,k,a,dp),f(i + 1,1,k,a,dp));
        }
        else{
            profit = max(a[i] + f(i + 1,1,k-1,a,dp),f(i + 1,0,k,a,dp));
        }
        return dp[i][buy][k] = profit;
    }   
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(3,vector<int>(k + 1,-1)));
        return f(0,2,k,prices,dp);
    }
};
