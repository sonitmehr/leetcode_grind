class Solution {
public:
    int dp[101][101][101];
    int f(int i, int j1,int j2,vector<vector<int>> &a){
        if(i < 0 || j1 < 0 || j2 < 0 || i >= a.size() || j1 >= a[0].size() || j2 >= a[0].size())return 0;

        if(i == a.size() - 1){
            if(j1 == j2)return a[i][j1];
            return a[i][j1] + a[i][j2];
        }
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        int maxi = 0;
        for(int ptr1 = -1;ptr1 <= 1;ptr1++){
            for(int ptr2 = -1;ptr2 <= 1;ptr2 ++){
                if(j1 == j2)maxi =max(maxi,a[i][j1] + f(i + 1,j1 +ptr1,j2 + ptr2,a ));

                else maxi = max(maxi,a[i][j1] + a[i][j2] + f(i+1,j1 + ptr1,j2 + ptr2,a));
            }
        }
        return dp[i][j1][j2] = maxi;


    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size(),m = grid[0].size();
        return f(0,0,m -1,grid);
    }
};
