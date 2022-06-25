class Solution {
public:
    
    int f(int i,int j,vector<vector<int>>& a,vector<vector<int>>& dp){
        if(j < 0 || j >=a.size())return 1e9;
        if(i == a.size()-1)return a[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        
        int l = a[i][j] + f(i+1,j,a,dp);
        int r = a[i][j] + f(i+1,j+1,a,dp);
        int p = a[i][j] + f(i+1,j-1,a,dp);
        return dp[i][j] = min({l,r,p});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans = 1e9;
        for(int i = 0;i<n;i++){
            ans = min(f(0,i,matrix,dp),ans);
        }
        return ans;
        
    }
};
