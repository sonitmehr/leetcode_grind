class Solution {
public:
    int dp[20][10001];
    int f(int i,int sum,vector<int>&a){
        if(i >= a.size())return 1e9;
        if(i == a.size() - 1){
            if(sum%a[i] == 0)return sum/a[i];
            return 1e9;
        }
        if(dp[i][sum] != -1)return dp[i][sum];

        int one = 1e9;
        if(sum - a[i] >= 0)one = 1 + f(i,sum - a[i],a);
        return dp[i][sum] = min(one,f(i+1,sum,a));

    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
       int ans =f(0,amount,coins);
       if(ans == 1e9)return -1;
       return ans;
    }
};
