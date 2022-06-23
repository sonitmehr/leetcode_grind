class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        //if(m ==1)return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = grid[0][0];
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0)continue;
                int l = 1e9,r=1e9;
                if(i > 0)l = grid[i][j] + dp[i-1][j];
                if(j > 0)r = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(l,r);
            }
        }
        return dp[m-1][n-1];
        
    }
};
