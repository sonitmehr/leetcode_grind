class Solution {
public:
    
    int f(int i,int j1,int j2,vector<vector<int>>& a,vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= a[0].size() || j2 < 0 || j2 >= a[0].size())return -1e9;
        if(i == a.size() -1){
            if(j1==j2)return a[i][j1];
            else return a[i][j1] + a[i][j2];
        }
        int maxi = -1e8;
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        for(int ptr1 = -1;ptr1 <= +1;ptr1++){
            for(int ptr2 = -1;ptr2<= +1;ptr2++){
                int val = 0;
                if(j1 == j2)val = a[i][j1];
                else val = a[i][j1] + a[i][j2];
                val += f(i+1,j1+ptr1,j2+ptr2,a,dp); 
                maxi = max(maxi,val);
            }
        }
        return dp[i][j1][j2] = maxi;
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int> (m,-1)));
        
        return f(0,0,m-1,grid,dp);
    }
};
