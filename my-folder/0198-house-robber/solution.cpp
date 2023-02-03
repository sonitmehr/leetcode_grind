class Solution {
public:
    int dp[1001];
    int f(int i, vector<int>&a){
        if(i >= a.size())return 0;
        if(i == a.size())return a[i];
        if(dp[i] != -1)return dp[i];
        int one = a[i] + f(i + 2,a);
        int two = f(i+1,a);

        return dp[i] = max(one,two);

    }
    int rob(vector<int>& v) {
        memset(dp,-1,sizeof(dp));

        return f(0,v);
    }
};
