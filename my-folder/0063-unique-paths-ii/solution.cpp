class Solution {
public:
    
    int f(int i,int j,vector<vector<int>> &a,vector<vector<int>> &dp){
        if(i>=0 && j>=0 && a[i][j] == 1)return 0;
        if(i ==0 && j == 0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int l = f(i-1,j,a,dp);
        int r = f(i,j-1,a,dp);
        return dp[i][j]= l+r;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1)); 
        dp[0][0] = 1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(obstacleGrid[i][j] == 1)dp[i][j] = 0;
                else if(i==0 && j ==0)continue;
                else {
                    int l=0,r=0;
                    if(i>0) l = dp[i-1][j];
                    if(j>0) r = dp[i][j-1];
                    dp[i][j] = l + r;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};
