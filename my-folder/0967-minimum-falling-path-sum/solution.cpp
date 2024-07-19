class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> dp(n,vector<int>(n,1e9));


        for(int i= 0;i<n;i++){
            dp[0][i] = mat[0][i];
        }

        for(int i = 1;i<n;i++){
            for(int j= 0;j<n;j++){
                int up = dp[i-1][j];
                int topLeft = 1e9;
                int topRight = 1e9;
                if(j - 1>=0)topLeft = dp[i - 1][j - 1];
                if(j + 1 < n)topRight = dp[i - 1][j + 1];

                dp[i][j] = mat[i][j] + min({topLeft,topRight,up});
            }
        }

        return *min_element(dp[n - 1].begin(),dp[n - 1].end());

        
    }
};
