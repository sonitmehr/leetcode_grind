class Solution {
public:
    int dp[301][10001];
    int f(int i,int sum,vector<int>&a){
        if(i >= a.size())return 1e9;
        if(i == a.size() - 1){
            if(sum%a[i] == 0)return 1;
            return 0;
        }
        if(dp[i][sum] != -1)return dp[i][sum];

        int one = 0;
        if(sum - a[i] >= 0)one = f(i,sum - a[i],a);
        return dp[i][sum] = one+f(i+1,sum,a);

    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
       int ans =f(0,amount,coins);
    //    if(ans == 1e9)return -1;
       return ans;
    }
};
