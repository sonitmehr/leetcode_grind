class Solution {
public:
    int vis[11][11];
    int maxi = 0;
    bool valid(int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
    void bfs(int i, int j,int n,int m,vector<vector<int>>& grid,int min){
        

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size(),m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                   q.push({{i,j},0});
                }
            }
        }
        vector<int> a = {-1,1,0,0},
                    b = {0,0,-1,1};
        
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int minutes = p.second;
            maxi = max(maxi,minutes);
            for(int k = 0;k<=3;k++){
                int newI = p.first.first + a[k],newJ = p.first.second + b[k];
                if(valid(newI,newJ,n,m) && vis[newI][newJ] == 0 && grid[newI][newJ] == 1){
                    vis[newI][newJ] = 1;
                    grid[newI][newJ] = 2;
                    q.push({{newI,newJ},minutes + 1});
                    
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    //cout << i << " " << j << endl;
                    return -1;
                }
            }
        }
        return maxi;
    }
};
