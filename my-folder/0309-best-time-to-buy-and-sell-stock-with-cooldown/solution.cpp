class Solution {
public:
    int dp[5001][3];
    int f(int i,int buy,vector<int>&a){
        if(i >= a.size())return 0;
        int one = 0;
        if(dp[i][buy] != -1)return dp[i][buy];
        if(buy){
            one = max(-a[i] + f(i + 1,0,a),f(i +1,1,a));

        }
        else{
            one = max(a[i] + f(i + 2,1,a),f(i + 1,0,a));
        }
        return dp[i][buy] = one;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(0,1,prices);
    }
};
