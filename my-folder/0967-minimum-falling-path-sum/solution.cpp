class Solution {
public:
    
    int f(int i,int j,vector<vector<int>>& a,vector<vector<int>>& dp){
        if(j < 0 || j >=a.size())return 1e9;
        if(i == 0)return a[0][j];
        if(dp[i][j] != -1)return dp[i][j];
        
        int l = a[i][j] + f(i-1,j,a,dp);
        int r = a[i][j] + f(i-1,j-1,a,dp);
        int p = a[i][j] + f(i-1,j+1,a,dp);
        return dp[i][j] = min({l,r,p});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans = 1e9;
        
        for(int i = 0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i = 1;i<m;i++){
            for(int j =0;j<n;j++){
                int l = 1e9,r=1e9,p=1e9;
                
                l = matrix[i][j] + dp[i-1][j];
                if(j -1>= 0) r = matrix[i][j] + dp[i-1][j-1];
                if(j +1< n) p = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min({l,r,p});
            }
        }
        for(int i = 0;i<n;i++){
            ans = min(ans,dp[m-1][i]);
        }
        return ans;
        
    }
};
