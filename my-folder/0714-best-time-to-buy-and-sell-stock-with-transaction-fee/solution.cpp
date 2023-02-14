class Solution {
public:
    int dp[50001][2];
    int fee;
    int f(int i,int buy,vector<int>&a){
        
        if(i >= a.size())return 0;

        int one = -1e9;
        if(dp[i][buy] != -1)return dp[i][buy];
        if(buy){
            one = max(-a[i] + f(i + 1,0,a),f(i + 1,1,a));
        }
        // sell
        else {
            one = max(a[i] - fee + f(i+1,1,a),f(i + 1,0,a));
        }
        return dp[i][buy] = one;
        
    }   
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        this->fee = fee;
        return f(0,1,prices);
    }
};
