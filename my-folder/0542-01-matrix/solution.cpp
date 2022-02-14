class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int rs = mat.size();
      int cs = mat[0].size();
      vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),-1));
      queue<pair<int, int>>q;
      for(int i=0; i<rs; i++){
        for(int j=0; j<cs; j++){
          if(mat[i][j] == 0){
            q.push({i, j});
            ans[i][j] = 0;
          }
        }
      }
      int dx[4] = {0, 0, 1, -1};
      int dy[4] = {1, -1, 0, 0};
      
      while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
          int nx = x + dx[i], ny = y + dy[i];
          if(nx<0 || nx>=rs || ny<0 || ny>=cs || ans[nx][ny]==0)continue;
          if(ans[nx][ny] == -1){
            ans[nx][ny] = ans[x][y]+1;
            q.push({nx, ny});
          }
        }
        
      }
      return ans;
    }
};
