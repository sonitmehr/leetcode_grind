class Solution {
public:
    int dp[100001][3][3];
    int f(int i,int buy,int k,vector<int>&a){
        if(i == a.size())return 0;
        if(k <= 0)return 0;
        int profit= 0;
        if(dp[i][buy][k] != -1)return dp[i][buy][k];
        if(buy){
            profit = max(-a[i] + f(i + 1,0,k,a),f(i + 1,1,k,a));
        }
        else{
            profit = max(a[i] + f(i + 1,1,k-1,a),f(i + 1,0,k,a));
        }
        return dp[i][buy][k] = profit;
    }   

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(0,2,2,prices);
    }
};
