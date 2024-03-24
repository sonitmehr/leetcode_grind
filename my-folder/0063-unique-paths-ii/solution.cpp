class Solution {
public:
/*
[0,1,0,0,0],
[1,0,0,0,0],
[0,0,0,0,0],
[0,0,0,0,0]
*/
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        // if(grid[0][0] == 1)return 0
;        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i= 0;i<m;i++){
            if(grid[0][i] != 1){
                dp[0][i] = 1;
            }
            else break;
        }
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                int one = 0,two = 0;

                if(grid[i][j] != 1){
                    if(i - 1>= 0)one = dp[i - 1][j];
                    if(j - 1>= 0)two = dp[i][j-1];
                }
                dp[i][j] = (one + two); 
            }

        }
        return dp[n - 1][m - 1];
        }
};
