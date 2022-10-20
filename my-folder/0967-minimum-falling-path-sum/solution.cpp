class Solution {
public:
    int n;
    int f(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp){
        if(j < 0 || j >= n)return 1e9;
        if(i == n - 1)return a[i][j];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int one = a[i][j] + f(i+1,j,a,dp);
        int two = a[i][j] + f(i+1,j+1,a,dp);
        int three = a[i][j] + f(i+1,j-1,a,dp);
        
        return dp[i][j] = min({one,two,three});
        
    }
    
    
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        this->n = n;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        int mini = 1e9;
        for(int i = 0;i<n;i++){
            mini = min(mini,f(0,i,a,dp));
        }
        return mini;
        
    }
};
