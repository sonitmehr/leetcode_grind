class Solution {
public:
    int dp[100001];
    int f(int i,vector<int> &a){
        if(i >=a.size())return 0;
        if(i == a.size())return a[i];
        if(dp[i] != -1)return dp[i];
        int one = a[i] + f(i+1,a);
        int two = a[i] + f(i + 2,a);

        return dp[i] = min(one,two);
        

    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int one = f(0,cost);
        memset(dp,-1,sizeof(dp));
        return min(one,f(1,cost));
    }
};
