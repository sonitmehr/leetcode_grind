class Solution {
public:
    int f(int i,int j,vector<vector<int>> &a,vector<vector<int>> &dp){
        if(i >= a.size() || j >= a[0].size())return 1e9;
        if(i == a.size()-1 && j == a[0].size()-1)return a[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int r = a[i][j] + f(i,j + 1,a,dp);
        int d = a[i][j] + f(i + 1,j,a,dp);
        
        return dp[i][j] = min(r,d);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1,vector<int>(grid[0].size() + 1,-1));
        
        return f(0,0,grid,dp);
        
    }
};
