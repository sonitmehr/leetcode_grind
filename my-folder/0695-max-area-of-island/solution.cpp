class Solution {
public:
    bool visited[52][52];
    int area, n, m;
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m || !grid[i][j] || visited[i][j]) return;        
        area++;
        visited[i][j] = true;
        dfs(i-1, j, grid); dfs(i+1, j, grid); //UP and Down
        dfs(i, j-1, grid); dfs(i, j+1, grid); //Left and Right
    }    
    int maxAreaOfIsland(vector<vector<int>>& grid){
        memset(visited, false, sizeof(visited));
        n = grid.size(); //Rows
        m = grid[0].size(); //Columns
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !visited[i][j]){
                    area = 0;
                    dfs(i, j, grid);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
    
};
