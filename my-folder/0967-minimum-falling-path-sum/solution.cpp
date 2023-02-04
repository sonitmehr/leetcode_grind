class Solution {
public:
    int dp[1001][1001];
    int f(int i, int j,int n, int m,vector<vector<int>>& grid){
       
        
        if(i >= n || i < 0 || j >=m || j < 0)return 1e9;
        if(i == (n -1))return grid[i][j];

        if(dp[i][j] !=-1)return dp[i][j];
        
        return dp[i][j] = grid[i][j] + min({f(i+1,j,n,m,grid),f(i+1,j-1,n,m,grid),f(i+1,j+1,n,m,grid)});
    }


    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(),m = grid[0].size();
        int mini = 1e9;
        memset(dp,-1,sizeof(dp));
        //int mini = 1e9;
        for(int k = 0;k<m;k++){
            mini = min(mini,f(0,k,n,m,grid));
        }    
        return mini;
    }
};
