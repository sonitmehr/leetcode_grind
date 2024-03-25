class Solution {
public:
    int maxTime = 0;
    vector<int> newI = {1,-1,0,0};
    vector<int> newJ = {0,0,1,-1};
    int rottenOranges = 0;
    bool check(int new_i,int new_j,int n,int m){
        if(new_i >= n || new_j >= m || new_i < 0 || new_j < 0)return false;
        return true;
    }

    void bfs(queue<pair<pair<int,int>,int>> &q,int n,int m,vector<vector<int>>& grid){
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int time = curr.second;
            int currI = curr.first.first;
            int currJ = curr.first.second;
            maxTime = max(maxTime,time);
            for(int k = 0;k<4;k++){
                int new_i = currI + newI[k];
                int new_j = currJ + newJ[k];

                if(check(new_i,new_j,n,m) && grid[new_i][new_j] == 1){
                    q.push({{new_i,new_j},time + 1});
                    grid[new_i][new_j] = 2;
                    rottenOranges ++;
                }
            }

        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;

        int totalOranges = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
               if(grid[i][j] == 2){
                    q.push({{i,j},0});
               }
               if(grid[i][j] == 1)totalOranges++;
            }

        }
        bfs(q,n,m,grid);
        
        return totalOranges == rottenOranges ? maxTime : -1;

    }
};
