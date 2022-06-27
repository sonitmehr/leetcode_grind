class Solution {
public:
    
    int f(int i,vector<int> &dp,vector<int> &a){
        if(i < 0 || i >= a.size())return 0;
        if(i == a.size()-1)return a[i];
        
        if(dp[i]!=-1)return dp[i];
        
        int l = a[i] + f(i+1,dp,a);
        int r = a[i] + f(i+2,dp,a);
        
        return dp[i] = min(l,r);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        vector<int> dp1(n+1,-1);
        int l = f(0,dp,cost);
        
        int r = f(1,dp1,cost);
        return min(l,r);
    }
};
