class Solution {
public:
    int f(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp){
        if(i == a.size()-1)return a[i][j];
        if(j < 0 || j>=a[i].size())return 1e9;
        
        if(dp[i][j] != -1)return dp[i][j];
        int l = a[i][j] + f(i+1,j,a,dp);
        int r = a[i][j] + f(i+1,j+1,a,dp);
        
        return dp[i][j] = min(l,r);
        
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return f(0,0,a,dp);
    }
};
