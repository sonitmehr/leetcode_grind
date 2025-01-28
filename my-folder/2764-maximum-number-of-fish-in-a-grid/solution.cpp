class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    bool check(int i, int j,int n,int m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int ans = 0;
    void dfs(int i, int j,int n,int m,vector<vector<int>> &grid){

        ans += grid[i][j];
        grid[i][j] = 0;
        for(int k = 0;k<=3;k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(check(x,y,n,m) && grid[x][y] > 0){
                
                dfs(x,y,n,m,grid);
            }

        }
        

    }

    int findMaxFish(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans = 0;
                if(grid[i][j] > 0){
                    dfs(i,j,n,m,grid);
                }
                maxi = max(maxi,ans);
            }
        }
        return maxi;

    }
};
