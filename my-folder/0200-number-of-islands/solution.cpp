class Solution {
public:
    int vis[301][301];
    bool valid(int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
    void dfs(int i,int j,int n,int m,vector<vector<char>>& grid){
        vector<int> a = {-1,1,0,0},
                    b = {0,0,-1,1};
        for(int k = 0;k<=3;k++){
            int addI = a[k],addJ = b[k];
            if(valid(i + addI,j + addJ,n,m) && grid[i + addI][j + addJ] == '1' && vis[i + addI][j + addJ] == 0 ){
                //cout << i << " " << j << endl;
                vis[i + addI][j + addJ] = 1;
                dfs(i + addI,j + addJ,n,m,grid);
            }
            
        }
    }

   void bfs(int i,int j,int n,int m,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<int> a = {-1,1,0,0},b = {0,0,-1,1};
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int newI = p.first,newJ = p.second;

            for(int k = 0;k<=3;k++){
                int addI = a[k], addJ = b[k];
                if(valid(newI + addI,newJ + addJ,n,m) && grid[newI + addI][newJ + addJ] == '1' && vis[newI + addI][newJ + addJ] == 0 ){
                    //cout << i << " " << j << endl;
                    vis[newI + addI][newJ + addJ] = 1;
                    q.push({newI + addI,newJ + addJ});

                }
            }
        }

   }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int ans = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    vis[i][j] = 1;
                    bfs(i,j,n,m,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
