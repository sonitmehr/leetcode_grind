class Solution {
public:
    
    int f(int i,int j,vector<vector<int>>& a,vector<vector<int>>& dp){
        //if(i < 0)return 0;
        if(i == a.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = 1e9;
        for(int k = 0;k<a.size();k++){
            if(k != j){
                int sum = a[i][k] + f(i+1,k,a,dp);
                mini = min(mini,sum);
            }
        }
        return dp[i][j] = mini;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n==1)return grid[0][0];
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int ans = 1e9;
        
        for(int i = 0;i<n;i++){
            ans = min(ans,f(0,i,grid,dp));
        }
        return ans;
    }
};
