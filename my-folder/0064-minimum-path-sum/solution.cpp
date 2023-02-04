class Solution {
public:
    int dp[1001][1001];
    int f(int i, int j,vector<vector<int>>& grid){
        if(i <0 || j < 0)return 1e9;
        if(i == 0 && j == 0)return grid[i][j];

        if(dp[i][j] != -1)return dp[i][j];

        return dp[i][j] = grid[i][j] + min(f(i-1,j,grid),f(i,j-1,grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size(),n = grid[0].size();
        return f(m-1,n-1,grid);
    }
};
